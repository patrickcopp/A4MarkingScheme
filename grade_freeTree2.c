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

//10:5:5:5
int main()
{
	struct Performance *perf= newPerformance();
	struct Node **node = malloc(sizeof(struct Node*));

	int *data = malloc(sizeof(int));
	*data=5;
	attachNode(perf,node,data,sizeof(int));

	struct Node **node2 = malloc(sizeof(struct Node*));
	*data = 4;
	attachNode(perf,node2,data,sizeof(int));
	(*node)->lt = *node2;

	struct Node **node3 = malloc(sizeof(struct Node*));
	*data = 6;
	attachNode(perf,node3,data,sizeof(int));
	(*node)->gte = *node3;

	struct Node **node4 = malloc(sizeof(struct Node*));
	*data = 6;
	attachNode(perf,node4,data,sizeof(int));
	(*node2)->gte = *node4;

	struct Node **node5 = malloc(sizeof(struct Node*));
	*data = 6;
	attachNode(perf,node5,data,sizeof(int));
	(*node3)->lt = *node5;

	freeTree(perf,node);

	_printPerf(perf);

	free(data);
	free(node);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(perf);
	return 0;
}

