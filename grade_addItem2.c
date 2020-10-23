#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

int compareInts(const void *s1, const void *s2)
{
	return *(const int *)s1-*(const int *)s2;
}

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//6:3:3:0
int main()
{
	struct Performance *perf= newPerformance();
	int * data = malloc(sizeof(int));

	struct Node **node = malloc(sizeof(struct Node*));
	*data = 5;
	attachNode(perf,node,data,sizeof(int));
	*data = 6;
	addItem(perf,node,compareInts,data,sizeof(int));
	*data = 7;
	addItem(perf,node,compareInts,data,sizeof(int));

	struct Node * right1 = (*node)->gte;
	struct Node * right2 = right1->gte;
	int * dataCopy = right2->data;

	if( *dataCopy==7)
		_printPerf(perf);

	free(data);
	free((*node)->lt);
	free((*node)->data);
	free(*node);
	free(right1->data);
	free(right1);
	free(right2->data);
	free(right2);
	free(node);
	free(perf);
	return 0;
}
