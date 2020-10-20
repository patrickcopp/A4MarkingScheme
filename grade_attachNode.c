#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT\0");
	attachNode(perf,node,data,8);
	if( perf->mallocs == 1 && perf->writes == 1 && perf->reads == 0 && perf->frees == 0 && (*node)->lt == NULL && (*node)->gte == NULL)
		printf("%s\r\n",(char *)((*node)->data));
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
