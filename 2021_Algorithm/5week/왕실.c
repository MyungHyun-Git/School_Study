#include <stdio.h>

char inputData[3];

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int main(void) {

	scanf("%s",inputData);
	int row = inputData[1] -'0';
	int column = inputData[0] -'a'+ 1;

	int result = 0;
	for(int i= 0; i< 8; i++) {
		int nextRow= row + dx[i];
		int nextColumn= column + dy[i];
		if(nextRow >= 1 && nextRow <= 8 && nextColumn >= 1 && nextColumn <= 8) {
			result += 1;
		}
	}
	printf("%d",result);
	return 0;
}
