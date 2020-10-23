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

//1:1:1:0
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));
	char data[10];
	strcpy(data,"CORRECT");
	attachNode(perf,node,data,8);
	strcpy(data,"INCORRECT");
	if( comparNode(perf,node,compareStrings,data)>0 )
		_printPerf(perf);
	free((*node)->data);
	free(*node);
	free(node);
	free(perf);
	return 0;
}
