#include <stdio.h>
#include <unistd.h>

main()
{
	printf("Executing execl..\n");

	execl("/bin/cal", "cal", "11","2019", 0);
	exit(1);
}
