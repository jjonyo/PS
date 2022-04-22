/*
	2022.04.22
	BOJ : 2512 예산 (https://www.acmicpc.net/problem/2512)
	Algorithm : 이분탐색
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ2512 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        String[] split = br.readLine().split(" ");
        int M = Integer.parseInt(br.readLine());

        int max = 0;
        int[] arr = new int[split.length];
        for (int i=0; i<split.length; i++) {
            arr[i] = Integer.parseInt(split[i]);
            max = Math.max(max, arr[i]);
        }

        if (sum(arr, max) <= M) {
            System.out.println(max);
            return;
        }


        int start = 1;
        int end = M;
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            int sum = sum(arr, mid);

            if (sum <= M) {
                start = mid + 1;
                ans = mid;
            } else {
                end = mid - 1;
            }
        }
        System.out.println(ans);
    }

    public static int sum(int[] arr, int maxinum) {
        int sum = 0;
        for (int i=0; i<arr.length; i++) {
            int num = arr[i];
            if (num > maxinum)
                num = maxinum;
            sum += num;
        }

        return sum;
    } 
}
