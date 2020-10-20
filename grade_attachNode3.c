#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	int *data = malloc (sizeof(int));
	*data = 5;
	attachNode(perf,node,data,sizeof(int));
	if( perf->mallocs == 1 && perf->writes == 1 && perf->reads == 0 && perf->frees == 0 && (*node)->lt == NULL && (*node)->gte == NULL && *((int*)((*node)->data))==5)
		printf("CORRECT\r\n");
	free(data);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
