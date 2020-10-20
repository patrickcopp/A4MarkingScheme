#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct Student
{
	char firstName[20];
	char lastName[20];
};

int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	struct Student *newKid = malloc(sizeof(struct Student));
	strcpy(newKid->firstName,"CORRECT\0");
	strcpy(newKid->lastName,"Doe\0");
	attachNode(perf,node,newKid,sizeof(struct Student));
	if( perf->mallocs == 1 && perf->writes == 1 && perf->reads == 0 && perf->frees == 0 && (*node)->lt == NULL && (*node)->gte == NULL)
		printf("%s\r\n",((struct Student *)((*node)->data))->firstName);
	free(newKid);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
