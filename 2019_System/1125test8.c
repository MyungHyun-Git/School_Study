#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
	printf("Executing execl.. \n");
	
	execl("/bin/ls", "ls", "-l", (char *)0);
	perror("execl failed");
	exit(1);
}
