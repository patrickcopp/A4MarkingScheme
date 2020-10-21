#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareStrings(const void *s1, const void *s2)
{
	return strcmp((const char *)s1,(const char *)s2);
}

int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT\0");
	attachNode(perf,node,data,8);

	struct Node **node2 = malloc(sizeof(struct Node*));
	strcpy(data,"INCORRECT\0");
	attachNode(perf,node2,data,10);

	(*node)->lt = *node2;
	struct Node **node3 = next(perf,node,-1);

	if( strcmp((char *)((*node3)->data),data)==0 && perf->mallocs == 2 && perf->writes == 2 && perf->reads == 1 && perf->frees == 0 && (*node)->gte == NULL)
		printf("%s\r\n",(char *)((*node)->data));

	free((*node2)->data);
	free((*node)->data);
	free(*node);
	free(*node2);
	free(node);
	free(node2);
	free(perf);
	return 0;
}
