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
	char data[10];
	char *dataCopy = malloc(10);
	strcpy(data,"CORRECT");
	attachNode(perf,node,data,8);
	readNode(perf,node,dataCopy,8);

	if( strcmp(dataCopy,data)==0 )
		_printPerf(perf);
	
	free(dataCopy);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
