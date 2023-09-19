package com.algorithm;

import java.util.Scanner;

public class EvenOdd {
    static boolean isEvenOrOdd(int num) { 

        if ((num ^ 1) == num + 1) {
            return true; 
        }
        else return false; 
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int num = scanner.nextInt();
        scanner.close();

        if (isEvenOrOdd(num))
            System.out.println("Even");
        else
            System.out.println("Odd");

    }
}
