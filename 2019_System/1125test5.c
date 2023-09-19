#include <stdlib.h>
#include <stdio.h>

main()
{
	int exit_s;

	printf("Enter exit status:");
	scanf("%d", &exit_s);
	exit(exit_s);
}
