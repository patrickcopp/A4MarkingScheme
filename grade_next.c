#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareStrings(const void *s1, const void *s2)
{
	return strcmp((const char *)s1,(const char *)s2);
}

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//1:2:2:0
void testOne()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT");
	attachNode(perf,node,data,8);

	struct Node **node2 = malloc(sizeof(struct Node*));
	strcpy(data,"INCORRECT");
	attachNode(perf,node2,data,10);

	(*node)->gte = *node2;
	struct Node **node3 = next(perf,node,1);

	if( strcmp((char *)((*node3)->data),data)==0 )
		_printPerf(perf);

	free((*node2)->data);
	free((*node)->data);
	free(*node);
	free(*node2);
	free(node);
	free(node2);
	free(perf);
}
//1:2:2:0
void testTwo()
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