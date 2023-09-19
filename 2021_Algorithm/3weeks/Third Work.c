#include <stdio.h>
#include <string.h>

int main(){
    int count=0;
    int sum=0;
    int n;
    scanf("%d", &n);
    int P[n], Q[n], S[n];
    int result = 0;
    
    for(int i=0; i<sizeof(Q)/sizeof(int); i++){
        scanf("%d", &Q[i]);
    }
    
    for(int a=0; a<sizeof(Q)/sizeof(int); a++){
        for(int b=0; b<sizeof(Q)/sizeof(int); b++){
            if(Q[a] > Q[b]){
                count = count + 1;
            }
        }
        if(P[count] == Q[a]){
            while(count < n){
                count++;
                if(P[count] != Q[a]){
                    P[count] = Q[a];
                    break;
                }
            }
        }
        else{
            P[count] = Q[a];
        }
        count = 0;
    }
    
    for(int c=0; c<n; c++){
        for(int d=c; d>=0; d--){
           sum = sum + P[d];
        }
        S[c] = sum;
        result = result + S[c];
        sum = 0;
    }
    printf("%d", result);
}
