#include <stdio.h>

int n;
char plans[100];
int x = 1, y = 1;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char moveTypes[4] = {'L', 'R', 'U', 'D'};

int main(void) {
	scanf("%d\n",&n);
	int i=0;
	int count = 0;
	char ch;
  
	while((ch=getchar())!=EOF){
	    plans[count++]=ch;
	    getchar();
	}

	for(i= 0; i<count; i++) {
	    char plan = plans[i];
		  int nx= -1, ny= -1;
		  for(int j = 0; j < 4; j++) {
			  if(plan == moveTypes[j]) {
				  nx= x + dx[j];
				  ny= y + dy[j];
			  }
		  }
		if(nx < 1|| ny < 1|| nx > n || ny > n){
			continue;
		}
		
		x = nx;
		y = ny;
	}
	printf("%d %d",x,y);
	return 0;
}
