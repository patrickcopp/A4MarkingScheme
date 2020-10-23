#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//0:1:1:0
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	int *data = malloc (sizeof(int));
	*data = 5;
	attachNode(perf,node,data,sizeof(int));
	if( (*node)->lt == NULL && (*node)->gte == NULL && *((int*)((*node)->data))==5)
		_printPerf(perf);
	free(data);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
