#include <stdio.h>
#include <search.h>
#define TABLESIZE 5

int compare(const void *ap, const void *bp)
{
	return ( *(int *)ap - *(int *)bp);
}


int main()
{
	int table [TABLESIZE] = {1,2,3,4,5};
	unsigned int n=TABLESIZE;
	int item, *ptr;

	item = 6;
	ptr = (int *)lsearch(&item, table, &n, sizeof(int), compare);
	if(ptr >= table+n-1)
		printf("%d is not in the table(1-%d), but added.\n", item,n);
	else
		printf("%d is int the table (1-%d).\n", *ptr, n);
	
	item = 7;
	ptr = (int *) lfind(&item, table, &n, sizeof(int), compare);
	if(ptr==NULL)
		printf("%d is not in the table(1-%d).\n", item,n);
	else
		printf("%d is in the table(1-%d).\n", *ptr,n);
}
