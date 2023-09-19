/*
file size.c
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>


main(int argc, char *argv[])
{
	int fd;
	off_t size;

	fd = open(argv[1], O_RDONLY);
	size = lseek(fd, 0, SEEK_END);

	printf("%s's size is : %d\n", argv[1], size);
	close(fd);

}
