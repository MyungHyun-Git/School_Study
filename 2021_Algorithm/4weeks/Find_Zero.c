#include <stdio.h>

int main(){
    int arr1[] = {2,3,0,0,4,0,6};
    int n = sizeof(arr1) / sizeof(int);
    
    int arr2[n];
    int j = 0;
    
    for(int i=0; i<n; i++){
        if(arr1[i] != 0){
            arr2[j] = arr1[i];
            j = j+1;
        }
    }
    
    for(int a=j; a<n; a++){
        arr2[a] = 0;
    }
    
    for(int b=0; b<n; b++){
        printf("%d ", arr2[b]);    
    }
    
}
