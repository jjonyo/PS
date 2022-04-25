/*
    2022.04.25
    BOJ : 17609 회문 (https://www.acmicpc.net/problem/17609)
    Algorithm : 투포인터
*/

import java.util.*;
import java.io.*;

public class BOJ17609 {

    static int N;
    static String[] strs;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        strs = new String[N];
        for (int i=0; i<N; i++) {
            strs[i] = br.readLine();
        }
    }

    public static int isPalindrome(String s, boolean isUse) {
        boolean isUsed = isUse;

        int l = 0;
        int r = s.length() - 1;
        char[] str = s.toCharArray();

        while (l < r) {
            if (str[l] == str[r]) {
                l++;
                r--;
            } else {
                if (!isUsed) {
                    int left = isPalindrome(s.substring(l + 1, r + 1), true);
                    int right = isPalindrome(s.substring(l , r), true);
                    if (left == 0 || right == 0) return 1;
                }
                return 2;
            }
        }

        return 0;
    }

    public static void main(String[] args) throws IOException {
        input();

        for (int i=0; i<N; i++) {
            System.out.println(isPalindrome(strs[i], false));
        }
    }
}