#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//0:1:1:1
void testOne()
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
}

//0:1:1:1
void testTwo()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	int* data = malloc(sizeof(int));
	*data = 5;
	attachNode(perf,node,data,(sizeof(int)));
	detachNode(perf,node);

	if( (*node)==NULL)
		_printPerf(perf);
	free(data);
	free(node);
	free(perf);
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage Incorrect- ./[exe] [1-2]\r\n");
		return -1;
	}
	if(strcmp(argv[1],"1")==0)
	{
		testOne();
	}
	else if(strcmp(argv[1],"2")==0)
	{
		testTwo();
	}
	else
	{
		printf("Usage incorrect- ./[exe] [1-2]\r\n");
	}
	return 0;
}