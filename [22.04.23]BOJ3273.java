/*
    2022.04.23
    BOJ : 3273 두 수의 합 (https://www.acmicpc.net/problem/3273)
    Algorithm : 이분탐색
*/

import java.util.*;
import java.io.*;

public class BOJ3273 {

    static int N;
    static int[] arr;
    static int x;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        
        N = Integer.parseInt(br.readLine());
        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for (int i=0;i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        x = Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) throws IOException {
        input();

        Arrays.sort(arr);

        int ans = 0;
        for (int i=0; i<N; i++) {
            int num = arr[i];

            //num + ? = x 만족하는 값이 있는지 찾기.
            if (binarySearch(i + 1, num)) 
            {
                ans ++;
            }
        }

        System.out.println(ans);
    }

    public static boolean binarySearch(int idx, int num) {
        int start = idx;
        int end = N - 1;

        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (num + arr[mid] == x) return true;
            else if (num + arr[mid] < x) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return false;
    }
}