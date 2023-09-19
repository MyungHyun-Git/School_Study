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
	}

	else if(pid>0)
	{
		wait( (int *)0);
		execl("/bin/cal", "cal", "11", "2019", 0);
	}

}
