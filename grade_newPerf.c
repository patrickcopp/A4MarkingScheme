#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
int main()
{
	struct Performance *perf = newPerformance();
	if(perf!=NULL && perf->reads==0 && perf->writes==0 && perf->mallocs==0 && perf->frees==0)
	{
		printf("CORRECT\r\n");
	}
	else
	{
		printf("INCORRECT\r\n");
	}
	free(perf);
	return 0;
}
