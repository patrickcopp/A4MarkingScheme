#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//1:1:1:0
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	int *data = malloc(sizeof(int));
	int *dataCopy = malloc(sizeof(int));
	*data = 5;
	attachNode(perf,node,data,(sizeof(int)));
	readNode(perf,node,dataCopy,(sizeof(int)));

	if( (*data)==(*dataCopy) )
		_printPerf(perf);
	
	free(data);
	free(dataCopy);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
