#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//0:1:1:1
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT");
	attachNode(perf,node,data,8);
	detachNode(perf,node);

	if( (*node)==NULL )
		_printPerf(perf);
	free(node);
	free(perf);
	return 0;
}
