/*
    2022.04.24
    BOJ : 2559 수열 (https://www.acmicpc.net/problem/2559)
    Algorithm : 투포인터
*/

import java.util.*;
import java.io.*;

public class BOJ2559 {

    static int N, K;
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

        int ans = Integer.MIN_VALUE;
        
        int l = 0;
        int r = 0;

        int sum = 0;
        int cnt = 0;
        while (true) {
            if (cnt >= K) {
                if (cnt == K) 
                    ans = Math.max(ans, sum);
                sum -= arr[l++];
                cnt--;
            } else if (r >= N) break;
            else {
                sum += arr[r++];
                cnt++;
            }
        }
        System.out.println(ans);
    }
}