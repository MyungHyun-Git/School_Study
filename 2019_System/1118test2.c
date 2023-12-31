#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

const char *endstring =""; // null

main(int argc, char *argv[])
{
	int fd;
	off_t hole_size;
	off_t size;

	fd = open(argv[1], O_RDWR);

	hole_size = atoi(argv[2]); //int -> string
	size = lseek(fd, 0, SEEK_END);
	printf("Before %s's size : %d\n", argv[1], size);
	lseek(fd,hole_size,SEEK_END);
	write(fd, endstring,1); // last + null 
	size = lseek(fd, 0, SEEK_END);
	printf("After %s's size : %d\n", argv[1],size);
	close(fd);
}
