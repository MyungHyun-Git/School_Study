#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
	DIR *pdir;
	struct dirent *pde;
	int i = 0;

	pdir = opendir(argv[1]);
	while((pde=readdir(pdir)) != NULL)
	{
		printf("%20s ", pde->d_name);
		if(++i%3 == 0)
			printf("\n");
	}
	printf("\n");
	closedir(pdir);
}
