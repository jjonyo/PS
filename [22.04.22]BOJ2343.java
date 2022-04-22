/*
	2022.04.22
	BOJ : 2343 기타레슨 (https://www.acmicpc.net/problem/2343)
	Algorithm : 이분탐색
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2343 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];
        for (int i=0;i<N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }


        int start = 1;
        int end = 1000000000;

        int ans = Integer.MAX_VALUE;
        while (start <= end) {
            int mid = (start + end) / 2;
        
            int cnt = 1;
            int sum = 0;
            for (int i=0; i<N; i++) {
                if (arr[i] > mid) {
                    cnt = Integer.MAX_VALUE;
                    break;
                }

                if (sum + arr[i] <= mid) {
                    sum += arr[i];
                } else {
                    cnt++;
                    sum = arr[i];
                }

                if (cnt > M) break;
            }
            
            //개수가 가능한 수보다 많으면 블루레이 크기를 늘려야 한다.
            if (cnt > M) {
                start = mid + 1;
            } else { //개수가 가능한 수보다 적거나 같으면, 값을 줄여봐야 한다.
                end = mid - 1;
                ans = Math.min(ans, mid);
            }
        }
        System.out.println(ans);
    }
}
