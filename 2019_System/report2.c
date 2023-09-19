#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,x;
	for(i=0; i<20; i++)
	{
		x=(int)(6*(rand()/(RAND_MAX+1.0) ) +1);
		printf("%d ",x);
	}
	printf("\n");
}
