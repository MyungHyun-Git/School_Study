#include <stdio.h>
#include <unistd.h>

main()
{
	printf("Executing execl..\n");

	execlp("cal", "cal", "11","2019", 0);
	exit(1);
}
