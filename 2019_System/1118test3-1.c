#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#define MAX_READ 10

main(int argc, char *argv[])
{
	int src;
	char buf[MAX_READ];
	ssize_t rcnt;
	ssize_t tot_cnt=0;
	mode_t mode=0644;

	src=open(argv[1], O_RDONLY);

	while( (rcnt = read(src, buf, MAX_READ))>0)
		tot_cnt += write(1,buf,rcnt);	
		
	
		

	printf("total write count = %d\n", tot_cnt);
	close(src);
	
}
