#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
	pid_t pid;
	pid=fork();

	if(pid==0)
	{
		execl("/bin/ls", "ls", "-l", 0);
		perror("fail");
	}
	else if(pid>0)
	{
		wait( (int *)0 );
		printf("ls ok\n");
		exit(0);
	}
	else
	{
		perror("fork fail");
	}

}
