#include <stdio.h>

int main()
{
	int a = 10;
	int b = 100;
	a = a + 10;
	sleep(3);
	int pid = fork();
	//fork() 

	if(pid > 0)
	{
		printf("parent process\n");
		a = a + 10;
		printf("[Parent] a = %d , b = %d \n", a,b);
		sleep(5);	
	}
	else if(pid == 0)
	{
		printf("Son process\n");
		b = b * 10;
		printf("[Child] a = %d, b = %d\n", a,b);
		sleep(5);
	}
	else
	{
		printf("I Can't Fork");
	}

	return 0;
}
