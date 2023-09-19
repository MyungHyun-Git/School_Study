#include <stdio.h>

int main() {
    int coin_num, value_num; 
	//coin_num:동전의 갯수, value_num:가격
    int count = 0;
  	//count:몇번 교환되는지 check
    
	printf("동전갯수와 만들 가격을 정해주세요\n");
	scanf("%d %d", &coin_num, &value_num);
	int coin[coin_num];
	printf("동전 갯수만큼 동전종류를 입력해주세요\n");
	
	for(int i=0; i<coin_num; i++){
	   scanf("%d", &coin[i]);
	}
	
	//여기까지 동전갯수, 가격을 입력받고 동전갯수만큼 배열을 생성해 동전을 입력한다.
	
	for(int j=0; j<coin_num; j++){
	    if(value_num<coin[j+1]){
	        value_num = value_num - coin[j];
	        count = count+1;
	        if(value_num == 0){
	            printf("최소 갯수 : %d", count);
	            break;
	        }
	        j=0;
	        continue;
	    }
	}
	// 동전갯수만큼 반복문을 돌린다.
	// 배열내 동전값이 value_num보다 커지면 바로 전 동전값을 value_num에서 빼고 count를 증가시킨다. 그 후 반복문을 처음부터 다시 돌도록 한다.
	// count 계산이 끝나 value_num이 0이되면 count를 출력하고 반복문을 탈출한다.
	return 0;
}
