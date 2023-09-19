#include <unistd.h>
#include <stdio.h>

#define MSGSIZE 16

char *msg[2] = {"Hello", "World"};

main()
{
	char buf[MSGSIZE];
	int p[2], i;
	int pid;
	pipe(p);
	
	pid=fork();
	if(pid==0)
	{
		close(p[0]);
		for(i=0; i<2; i++){
			sprintf(buf,"Hello, world #%d", i+1);	
			write(p[1], buf, MSGSIZE); // p[1] = buf
		}

	}

	else if(pid>0)
	{
		close(p[1]);
		for(i=0;i<2;i++)
		{
			read(p[0], buf, MSGSIZE); //p[0] = buf
			printf("%s \n", buf);
		}
	}

	else
		perror("fork failed");
}
