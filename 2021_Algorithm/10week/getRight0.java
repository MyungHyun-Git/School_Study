package com.algorithm;

public class Right0 {
    static int getPosOfRightmostSetBit(int n) { 
        return (int) (Math.log(~n & (n+1)) / Math.log(2)) + 1;
    }

    static int setRightmostUnsetBit(int n) {
        if (n == 0) return 1;
        if ((n & (n+1)) == 0) return n;

        int pos = getPosOfRightmostSetBit(n);
        System.out.println("제일 끝의 0 위치 : " + pos + "번째");
        return ((1 << pos - 1) | n); 
    }

    public static void main(String[] args) {
        int n = 21;
        System.out.println(setRightmostUnsetBit(n));
    }
}
