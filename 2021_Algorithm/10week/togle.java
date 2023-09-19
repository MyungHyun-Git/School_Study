package com.algorithm;

import java.util.Scanner;

public class ToggleCase {

    static char[] toggle(String str) {
        char[] temp = str.toCharArray();

        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ' ') continue;
            temp[i] = (char) (str.charAt(i) ^ 32);
        }

        return temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        scanner.close();

        System.out.println(toggle(str));
    }
}
