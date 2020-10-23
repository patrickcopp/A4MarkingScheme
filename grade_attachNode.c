#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Student
{
	char firstName[20];
	char lastName[20];
};

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//0:1:1:0
void testOne()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT");
	attachNode(perf,node,data,8);
	if( (*node)->lt == NULL && (*node)->gte == NULL && strcmp((char *)((*node)->data),"CORRECT")==0)
		_printPerf(perf);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
}
//0:1:1:0
void testTwo()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	struct Student *newKid = malloc(sizeof(struct Student));
	strcpy(newKid->firstName,"CORRECT");
	strcpy(newKid->lastName,"Doe");
	attachNode(perf,node,newKid,sizeof(struct Student));
	if((*node)->lt == NULL && (*node)->gte == NULL && strcmp((char *)(((struct Student *)((*node)->data))->firstName),"CORRECT")==0)
		_printPerf(perf);
	free(newKid);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
}

//0:1:1:0
void testThree()
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
}


int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("Usage Incorrect- ./[exe] [1-3]\r\n");
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
	else if(strcmp(argv[1],"3")==0)
	{
		testThree();
	}
	else
	{
		printf("Usage incorrect- ./[exe] [1-3]\r\n");
	}
	return 0;
}
