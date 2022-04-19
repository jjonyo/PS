/*
	2022.04.20
	BOJ : 24460 특별상이라도 받고 싶어 (https://www.acmicpc.net/problem/24460)
	Algorithm : 재귀
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class BOJ24460 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        int[][] arr = new int[N][N];

        for (int i=0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0; j<N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(solve(arr, 0,0, N));
    }

    public static int solve(int[][] arr, int i, int j, int N) {
        if (N == 1)
            return arr[i][j];
        
        int next = N / 2;
        int[] result = new int[4];
        result[0] = solve(arr, i, j , next);
        result[1] = solve(arr, i + next, j , next);
        result[2] = solve(arr, i, j + next , next);
        result[3] = solve(arr, i + next, j + next , next);

        Arrays.sort(result);
        return result[1];
    }
}
