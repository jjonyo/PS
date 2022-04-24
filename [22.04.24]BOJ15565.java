/*
    2022.04.24
    BOJ : 15565 귀여운 라이언 (https://www.acmicpc.net/problem/15565)
    Algorithm : 이분탐색
*/

import java.util.*;
import java.io.*;

public class BOJ15565 {

    static int N,K;
    static int[] arr;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());


        N = Integer.parseInt(st.nextToken());    
        K = Integer.parseInt(st.nextToken());

        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        int ans = Integer.MAX_VALUE;

        int l, r;
        l = r = 0;

        int len = 0;
        int cnt = 0;
        while (true) {
            if (cnt >= K) {
                if (arr[l++] == 1)
                    cnt--;
                len--;
            } else if (r >= N) break;
            else {
                if (arr[r++] == 1)
                    cnt++;
                len++;
            }
            
            if (cnt == K) {
                ans = Math.min(ans, len);
            }
        }
        System.out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }
}