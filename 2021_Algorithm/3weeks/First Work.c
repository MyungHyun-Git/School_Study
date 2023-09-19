#include <stdio.h>

int n, k, result;

int main(){
    scanf("%d %d", &n, &k);
    while(1){
        if((n%k)==0){
            n=n/k;
        }
        else{
            n=n-1;
        }
        result++;
        if(n<k) break;
    }
    result = result+(n-1);
    printf("%d", result);
    return 0;
}
