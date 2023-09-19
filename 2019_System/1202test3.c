#include <stdio.h>
#include <pthread.h>

void *join_thread(void *arg)
{
	pthread_exit(arg);
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	int arg,status;
	void *result;

	if(argc<2)
	{
		fprintf(stderr, "Usage: jointhread<number> \n");
		exit(1);
	}
	arg=atoi(argv[1]);

	status=pthread_create(&tid, NULL, join_thread, (void *)arg);
	status = pthread_join(tid, &result); //result = pthread_exit(arg)'s arg
	return (int)result;
}
