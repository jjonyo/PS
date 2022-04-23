/*
    2022.04.23
    BOJ : 15970 화살표 그리기 (https://www.acmicpc.net/problem/15970)
    Algorithm : 정렬
*/

import java.util.*;
import java.io.*;

public class BOJ15970 {
    static int N;
    static ArrayList<Integer>[] arr;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        arr = new ArrayList[N + 1];

        for (int i=1; i<=N; i++) {
            arr[i] = new ArrayList<>();
        }

        for (int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());
            int color = Integer.parseInt(st.nextToken());

            arr[color].add(num);
        }
    }


    public static void main(String[] args) throws IOException {
        input();

        for (int i=1; i<=N; i++) {
            Collections.sort(arr[i]);
        }

        int ans = 0;
        for (int i=1; i<=N; i++) {
            if (arr[i].isEmpty()) continue;

            for (int j=0; j<arr[i].size(); j++) {
                int left = left(i, j);
                int right = right(i, j);
                
                if (left == Integer.MAX_VALUE && right == Integer.MAX_VALUE) continue;
                ans += Math.min(left, right);
            }
        }
        System.out.println(ans);
    }

    public static int right(int color, int index) {
        int min = Integer.MAX_VALUE;
        for (int i = index + 1; i < arr[color].size(); i++) {
            min = Math.min(min, Math.abs(arr[color].get(i) - arr[color].get(index)));
        }
        return min;
    }

    public static int left(int color, int index) {
        int min = Integer.MAX_VALUE;
        for (int i = index - 1; i >= 0; i--) {
            min = Math.min(min, Math.abs(arr[color].get(i) - arr[color].get(index)));
        }
        return min;
    }
}