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
int main()
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
	return 0;
}
