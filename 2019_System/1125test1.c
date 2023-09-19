#include <stdio.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	mkdir(argv[1] ,0777);
}
