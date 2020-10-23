#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareInts(const void *s1, const void *s2)
{
	return *(const int *)s1 - *(const int *)s2;
}

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

int main(int argc, char *argv[])
{
	if(argc!=2)
	{
		printf("Usage Incorrect- ./[exe] [1-5]\r\n");
		return -1;
	}
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));

	int *data = malloc(sizeof(int));
	*data=5;
	attachNode(perf,node,data,sizeof(int));

	struct Node **node2 = malloc(sizeof(struct Node*));
	*data = 2;
	attachNode(perf,node2,data,sizeof(int));
	(*node)->lt = *node2;

	struct Node **node3 = malloc(sizeof(struct Node*));
	*data = 7;
	attachNode(perf,node3,data,sizeof(int));
	(*node)->gte = *node3;

	struct Node **node4 = malloc(sizeof(struct Node*));
	*data = 3;
	attachNode(perf,node4,data,sizeof(int));
	(*node2)->gte = *node4;

	struct Node **node5 = malloc(sizeof(struct Node*));
	*data = 6;
	attachNode(perf,node5,data,sizeof(int));
	(*node3)->lt = *node5;


	int search = 0;

	//2:5:5:0
	if(strcmp(argv[1],"1")==0)
	{
		*data = 5;
		search = searchItem(perf,node,compareInts,data,sizeof(int));
		if(search==1)
			_printPerf(perf);
	}
	//4:5:5:0
	else if(strcmp(argv[1],"2")==0)
	{
		*data = 2;
		search = searchItem(perf,node,compareInts,data,sizeof(int));
		if(search==1)
			_printPerf(perf);
	}
	//6:5:5:0
	else if(strcmp(argv[1],"3")==0)
	{
		*data = 3;
		search = searchItem(perf,node,compareInts,data,sizeof(int));
		if(search==1)
			_printPerf(perf);
	}
	//4:5:5:0
	else if(strcmp(argv[1],"4")==0)
	{
		*data = 8;
		search = searchItem(perf,node,compareInts,data,sizeof(int));
		if(search==0)
			_printPerf(perf);
	}
	//6:5:5:0
	else if(strcmp(argv[1],"5")==0)
	{
		*data = 4;
		search = searchItem(perf,node,compareInts,data,sizeof(int));
		if(search==0)
			_printPerf(perf);
	}
	else
	{
		printf("Usage Incorrect- ./[exe] [1-5]\r\n");
	}


	free(data);
	free((*node)->data);
	free((*node2)->data);
	free((*node3)->data);
	free((*node4)->data);
	free((*node5)->data);

	free(*node);
	free(*node2);
	free(*node3);
	free(*node4);
	free(*node5);

	free(node);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(perf);
	return 0;
}

