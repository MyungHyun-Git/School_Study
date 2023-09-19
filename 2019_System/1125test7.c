#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
	pid_t pid;
	int status, exit_s;
	int i=1;
	

	while(i<=3)
	{
		pid=fork();

		if(pid==0)
		{
			printf("childe: %d\n",getpid());
			exit(0);
		}
		i++;
	}


			if(pid!=0)
		{
			printf("i'm parent:%d\n", getppid());
		}

	exit(0);
		

}
