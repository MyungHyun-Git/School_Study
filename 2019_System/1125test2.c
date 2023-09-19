#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	rmdir(argv[1]);
}
