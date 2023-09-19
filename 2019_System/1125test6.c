#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

main()
{
	pid_t pid;
	int status, exit_s;
	
	if( (pid=fork())<0 )
	{
		perror("fork failed");
	}

	if(pid==0)
	{
		sleep(4);
		exit(5);
	}

	if( (pid=wait(&status)) == -1)
	{
		perror("wait failed");
		exit(2);
	}

	if(WIFEXITED(status))
	{
		exit_s = WEXITSTATUS(status);
		printf("Exit status from %d was %d\n", pid, exit_s);
	}
	exit(0);

}
