/*
    2022.05.24
    BOJ : 23304 아카라카 (https://www.acmicpc.net/problem/23304)
    Algorithm : 재귀
*/

import java.util.*;
import java.io.*;

public class BOJ23304 {

    static String str;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        str = br.readLine();
    }

    public static void main(String[] args) throws IOException {
        input();

        if (solve(str)) {
            System.out.println("AKARAKA");
        }else {
            System.out.println("IPSELENTI");
        }
    }

    public static boolean solve(String s) {
        int n = s.length() / 2;
        if (n == 0) return true;
        if (!isPalindrome(s)) return false;

        boolean a = solve(s.substring(0, n));
        boolean b = solve(s.substring(s.length() - n, s.length()));

        return a & b;
    }

    public static boolean isPalindrome(String s) {
        int end = s.length() - 1;
        for (int i=0; i<s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(end - i)) return false;
        }

        return true;
    }
}