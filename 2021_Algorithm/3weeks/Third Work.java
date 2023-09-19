/*package whatever //do not write package name here */

import java.io.*;
import java.util.Scanner;

class GFG {
	public static void main (String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int count=0;
        int sum=0;
        int n;
        n = sc.nextInt();
        int[] P = new int[n];
        int[] Q = new int[n]; 
        int[] S = new int[n];
        int result = 0;
        
            for(int i=0; i<n; i++){
        Q[i] = sc.nextInt();
    }
    
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
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
    System.out.print(result);
	}
}
