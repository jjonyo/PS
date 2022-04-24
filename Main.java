/*
    2022.04.25
    BOJ : 16472 고냥이 (https://www.acmicpc.net/problem/16472)
    Algorithm : 투포인터
*/

import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static String str;
    static int[] count = new int[26];

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        str = br.readLine();
    }

    public static int getCount() {
        int cnt = 0;

        for (int i=0; i<26; i++) {
            if (count[i] != 0) cnt++;
        }

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        input();

        char[] arr = str.toCharArray();
        int length = arr.length;

        int l, r;
        l = r = 0;

        int ans = 0;
        while (true) {
            int cnt = getCount();
            if (cnt <= N) {
                ans = Math.max(ans, r - l);
            }
            
            if (cnt > N) {
                count[arr[l] - 'a']--;
                l++;
            } else if (r >= length) break;
            else {
                count[arr[r] - 'a']++;
                r++;
            }

        }
        System.out.println(ans);
    }
}