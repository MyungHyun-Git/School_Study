#include <stdio.h>
#include <string.h>

int main()
{
	char s[20], t[20], min[20];
	printf("char 1 ? ");
	scanf("%s", s);
	
	printf("char 2 ? ");
	scanf("%s", t);

	if(strcmp(s,t)<0)
		strcpy(min,s);
	else if (strcmp(s,t) >=0)
		strcpy(min,t);

	printf("%s\n",min);
}
