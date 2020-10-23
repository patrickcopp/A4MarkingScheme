#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareInts(const void *s1, const void *s2)
{
	return (const int *)s1-(const int *)s2;
}

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//1:2:2:0
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));

	int *data = malloc(sizeof(int));
	*data=5;
	attachNode(perf,node,data,sizeof(int));

	struct Node **node2 = malloc(sizeof(struct Node*));
	*data = 6;
	attachNode(perf,node2,data,sizeof(int));

	(*node)->lt = *node2;
	struct Node **node3 = next(perf,node,-1);

	if( *((int *)((*node3)->data)) == *data )
		_printPerf(perf);

	free(data);
	free((*node2)->data);
	free((*node)->data);
	free(*node);
	free(*node2);
	free(node);
	free(node2);
	free(perf);
	return 0;
}
