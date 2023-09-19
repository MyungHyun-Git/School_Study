#include <sys/types.h>
#include <unistd.h>

main()
{
	pid_t pid;
	printf("Calling fork\n");
	pid=fork();
	if(pid==0)
	{
		printf("I'm the child\n");
		printf("child pid=%d\n", getpid());
	}

	else if(pid>0)
	{
		printf("I'm the parent\n");
		printf("parent pid=%d\n", getpid());
	}

	else
		printf("fork failed\n");

	

}
