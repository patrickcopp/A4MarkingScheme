#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareStrings(const void *s1, const void *s2)
{
	return strcmp((const char *)s1,(const char *)s2);
}

int compareInts(const void *s1, const void *s2)
{
	return *(const int *)s1-*(const int *)s2;
}

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}
//2:2:2:0
void testOne()
{
	struct Performance *perf= newPerformance();
	char data[10];

	struct Node **node = malloc(sizeof(struct Node*));
	strcpy(data,"MIDDLE");
	attachNode(perf,node,data,7);

	strcpy(data,"CORRECT");
	addItem(perf,node,compareStrings,data,8);
	
	if( strcmp((char*)(((struct Node *)((*node)->lt))->data),"CORRECT")==0 )
		_printPerf(perf);
	
	free(((struct Node *)((*node)->lt))->data);
	free((*node)->lt);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
}
//6:3:3:0
void testTwo()
{
	struct Performance *perf= newPerformance();
	int * data = malloc(sizeof(int));

	struct Node **node = malloc(sizeof(struct Node*));
	*data = 5;
	attachNode(perf,node,data,sizeof(int));
	*data = 6;
	addItem(perf,node,compareInts,data,sizeof(int));
	*data = 7;
	addItem(perf,node,compareInts,data,sizeof(int));

	struct Node * right1 = (*node)->gte;
	struct Node * right2 = right1->gte;
	int * dataCopy = right2->data;

	if( *dataCopy==7)
		_printPerf(perf);

	free(data);
	free((*node)->lt);
	free((*node)->data);
	free(*node);
	free(right1->data);
	free(right1);
	free(right2->data);
	free(right2);
	free(node);
	free(perf);
}

int main(int argc, char *argv[])
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