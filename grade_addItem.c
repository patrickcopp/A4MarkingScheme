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

// 2:2:2:0
int main()
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
	return 0;
}