#include <stdio.h>
#include <string.h>

int main(){
    char str[20];
    scanf("%s", str);
    
    int result = str[0] - '0';
    for(int i=1; i<strlen(str); i++){
        int num = str[i] - '0';
        if(num<=1 || result<=1){
            result = result + num;
        }
        else{
            result = result * num;
        }
    }
    printf("%d", result);
}
