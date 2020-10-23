#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void _printPerf(struct Performance *perf)
{
	printf("%d:%d:%d:%d\r\n",perf->reads,perf->writes,perf->mallocs,perf->frees);
}

//0:0:0:0
int main()
{
	struct Performance *perf = newPerformance();
	if(perf!=NULL)
	{
		_printPerf(perf);
	}
	free(perf);
	return 0;
}
