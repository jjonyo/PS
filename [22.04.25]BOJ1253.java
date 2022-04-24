/*
    2022.04.25
    BOJ : 1253 좋다 (https://www.acmicpc.net/problem/1253)
    Algorithm : 투포인터
*/

import java.util.*;
import java.io.*;

public class BOJ1253 {

    static int N;
    static int[] arr;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i=0;i<N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Arrays.sort(arr);

        int ans = 0;
        for (int i=0; i<N; i++) {
            int target = arr[i];

            int start = 0;
            int end = N - 1;

            while (start < end) {
                if (start == i) {
                    start++;
                    continue;
                }
                if (end == i) {
                    end--;
                    continue;
                }

                int sum = arr[start] + arr[end];
                if (sum == target){
                    ans++;
                    break;
                }
                if (sum > target) {
                    end--;
                } else {
                    start++;
                }
            }
        }
        System.out.println(ans);
    }
}