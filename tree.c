#include "tree.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Performance *newPerformance()
{
  struct Performance *perf;

  perf = (struct Performance *)malloc( sizeof( struct Performance ) );
  if (!perf)
  {
    fprintf( stderr, "Malloc failure\n" );
    exit(-1);
  }

  perf->reads   = 0;
  perf->writes  = 0;
  perf->mallocs = 0;
  perf->frees   = 0;

  return perf;
}

void attachNode( struct Performance *performance, struct Node **node_ptr, void *src, unsigned int width )
{
  *node_ptr = (struct Node *)malloc( sizeof( struct Node ) );
  if (!(*node_ptr))
  {
    fprintf( stderr, "err\n" );
    exit(-1);
  }

  (*node_ptr)->data = malloc( width );
  if (!((*node_ptr)->data))
  {
    fprintf( stderr, "err\n" );
    exit(-1);
  }

  (*node_ptr)->lt = NULL;
  (*node_ptr)->gte = NULL;
  memcpy( (*node_ptr)->data, src, width );

  performance->mallocs++;
  performance->writes++;
}

int comparNode( struct Performance *performance, struct Node **node_ptr, 
                int (*compar)(const void *, const void *), void *target )
{
  performance->reads++;
  return compar( target, (*node_ptr)->data );
}

struct Node **next( struct Performance *performance, struct Node **node_ptr, 
                    int direction )
{
  if (!(*node_ptr))
  {
    fprintf( stderr, "err\n" );
    exit(-1);
  }
  performance->reads++;

  if (direction<0)
  {
    return &((*node_ptr)->lt);
  }
  else
  {
    return &((*node_ptr)->gte);
  }
}

void readNode( struct Performance *performance, struct Node **node_ptr, 
               void *dest, unsigned int width )
{
  if (!(*node_ptr))
  {
    fprintf( stderr, "err\n" );
    exit(-1);
  }
  memcpy( dest, (*node_ptr)->data, width );
  performance->reads++;
}

void detachNode( struct Performance *performance, struct Node **node_ptr )
{
  if (!(*node_ptr))
  {
    fprintf( stderr, "err\n" );
    exit(-1);
  }

  free( (*node_ptr)->data );
  free( (*node_ptr) );
  *node_ptr = NULL;
  performance->frees++;
}

/* derived functions */

void addItem( struct Performance *performance, struct Node **node_ptr, 
              int (*compar)(const void *, const void *),
              void *src, unsigned int width )
{
  while (*node_ptr)
  {
    int direction = comparNode( performance, node_ptr, compar, src );
    node_ptr = next( performance, node_ptr, direction );
  }
  attachNode( performance, node_ptr, src, width );
}

void freeTree( struct Performance *performance, struct Node **node_ptr )
{
  if (*node_ptr)
  {
    freeTree( performance, next( performance, node_ptr, -1 ) );
    freeTree( performance, next( performance, node_ptr, +1 ) );
    detachNode( performance, node_ptr );
  }
}

int searchItem( struct Performance *performance, struct Node **node_ptr, 
                int (*compar)(const void *, const void *),
                void *target, unsigned int width )
{
  if (*node_ptr)
  {
    int direction = comparNode( performance, node_ptr, compar, target );
    if (direction==0)
    {
      readNode( performance, node_ptr, target, width );
      return 1;
    }
    else
    {
      return searchItem( performance, next( performance, node_ptr, direction ),
	          compar, target, width );
    }
  }
  else
  {
    return 0;
  }
}
