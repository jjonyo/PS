/*
    2022.04.23
    BOJ : 13702 이상한 술집 (https://www.acmicpc.net/problem/13702)
    Algorithm : 이분탐색
*/

import java.util.*;
import java.io.*;

public class BOJ13702 {

    static int N,K;
    static int[] list;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
    
        list = new int[N];
        for (int i=0; i<N; i++) {
            list[i] = Integer.parseInt(br.readLine());
        }
    }

    public static boolean isSolve(long mid) {
        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (list[i] == 0) continue;
            long div = list[i] / mid;
            
            cnt += div;
        }

        return cnt >= K;
    }

    public static void main(String[] args) throws IOException {
        input();

        Arrays.sort(list);
        
        int start = 0;
        int end = Integer.MAX_VALUE;
        long ans = 0;
        while (start <= end) {
            long mid = ((long) start + end) / 2;
            //mid일때, K명이 먹을 수 있냐?
            if (!isSolve(mid)) { //mid일때 K명이 먹을 수 없으면 -> mid의 크기를 줄여본다.
                end = (int)mid - 1;
            } else {  //K 명이 먹을 수 있으면, 최대의 mid를 찾아 본다.
                start = (int)mid + 1;
                ans = mid;
            }
        }
        System.out.println(ans);
    }
}