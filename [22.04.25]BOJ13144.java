/*
    2022.04.25
    BOJ : 13144 List of Unique Numbers (https://www.acmicpc.net/problem/13144)
    Algorithm : 투포인터, 카운팅 정렬
*/

import java.util.*;
import java.io.*;

public class BOJ13144 {

    static int N;
    static int[] arr;
    static int[] count;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[N];
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        count = new int[100001];
    }

    public static void main(String[] args) throws IOException {
        input();

        long ans = 0;

        int l = 0;
        int r = 0;

        while (l < N) {
            while (r < N && count[arr[r]] == 0) {
                count[arr[r]] = 1;
                r++;
            }

            ans += r - l;
            count[arr[l]] = 0;
            l++;
        }
        System.out.println(ans);
    }
}