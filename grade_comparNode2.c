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
	strcpy(data,"INCORRECT\0");
	if( comparNode(perf,node,compareStrings,data)>0 && perf->mallocs == 1 && perf->writes == 1 && perf->reads == 1 && perf->frees == 0 && (*node)->lt == NULL && (*node)->gte == NULL)
		printf("%s\r\n",(char *)((*node)->data));
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
