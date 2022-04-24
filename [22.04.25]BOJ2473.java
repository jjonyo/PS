/*
    2022.04.25
    BOJ : 2473 세 용액 (https://www.acmicpc.net/problem/2473)
    Algorithm : 투포인터
*/

import java.util.*;
import java.io.*;

public class BOJ2473 {

    static int N;
    static int[] arr;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Arrays.sort(arr);

        long ans = Long.MAX_VALUE;
        int[] answerList = new int[3];
        
        for (int i=0; i< N - 2; i++) {
            int l = i + 1;
            int r = N - 1;
            while (l < r) {
                long sum = (long)arr[i] + arr[l] + arr[r];

                if (Math.abs(sum) < ans) {
                    ans = Math.abs(sum);
                    answerList[0] = arr[i];
                    answerList[1] = arr[l];
                    answerList[2] = arr[r];
                }

                if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        Arrays.sort(answerList);
        for (int n : answerList) {
            System.out.print(n + " ");
        }
    }
}