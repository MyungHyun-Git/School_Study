#include <stdio.h>
#include <unistd.h>

main()
{
	char * const argv[]={"ls","-l", (char *)0};
	printf("Executing execl..\n");
	

	execv("/bin/ls", argv);
	exit(1);
}
