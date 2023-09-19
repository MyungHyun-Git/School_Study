#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


main(int argc, char *argv[])
{
	struct stat buf;
	char *msg;
	stat(argv[1],&buf);
	
	

	printf("Filename / inode NO / link / filesize / blocksize / number of blocks\n");
	printf("%s /   %d   / %d  /   %d    /%ld       / %ld \n",argv[1],buf.st_ino,buf.st_nlink,buf.st_size,buf.st_blksize,buf.st_blocks);

	


}
