#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3

pthread_mutex_t mutex;
int sum;

void *mutex_thread(void *arg)
{
	pthread_mutex_lock(&mutex);
	sum = sum + (int)arg;
	pthread_mutex_unlock(&mutex);

	return arg;
}

int main(int argc, char *argv[])
{
	pthread_t tid[NUM_THREADS];
	int arg[NUM_THREADS], i;
	void *result;
	int status;

	for(i=0; i<NUM_THREADS; i++)
	{
		arg[i]=atoi(argv[i+1]);
	}
	pthread_mutex_init(&mutex,NULL);

	for(i=0; i<NUM_THREADS; i++)
	{
		status=pthread_create(&tid[i],NULL,mutex_thread,(void *)arg[i]);
		pthread_join(tid[i],&result);
	}
	pthread_mutex_destroy(&mutex);

	printf("sum is %d\n",sum);
	pthread_exit(result);
}
