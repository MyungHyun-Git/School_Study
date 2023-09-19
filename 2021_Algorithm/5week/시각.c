#include <stdio.h>
int h, cnt=0;
int check(int h, int m, int s) {
	if (h % 10== 3|| m / 10== 3|| m % 10== 3|| s / 10== 3|| s % 10== 3)
		return 1;
	
	return 0;
}
int main(void) {
	scanf("%d",&h);
	
	for(int i= 0; i<= h; i++) {
		for(int j = 0; j < 60; j++) {
			for(int k = 0; k < 60; k++) {
				if(check(i, j, k)) cnt++;
			}
		}
	}
	printf("%d",cnt);
	
	return 0;
}
