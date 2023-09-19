#include <stdio.h>
#include <math.h>

int main()
{
	double x;
	printf("x=%10s / log(x)=%10s / sqrt(x)=%10s / exp(x)=%15s / pow(10.0,x)=%20s\n","x","log(x)","sqrt(x)","exp(x)","pow(10.0,x)");

	for(x=1; x<=10; x++)
	{
		printf("x=%10.5f / log(x)=%10.5f / sqrt(x)=%10.5f / exp(x)=%15.5f / pow(10.0,x)=%20.5f\n", x,log(x),sqrt(x),exp(x),pow(10.0,x));
	}
}
