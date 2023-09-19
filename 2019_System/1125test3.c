#include <unistd.h>
#include <stdio.h>
main(int argc, char *argv[])
{
	link(argv[1], argv[2]);
}
