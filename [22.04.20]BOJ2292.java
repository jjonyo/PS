/*
	2022.04.20
	BOJ : 2292 벌집 (https://www.acmicpc.net/problem/2292)
	Algorithm : 수학
*/
import java.util.Scanner;

public class BOJ2292 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();

        int num = 1;
        int cnt = 1;
        int add = 6;

        while (true) {
            if (num >= N) break;
            num += add;
            cnt ++;
            add = add + 6;
        }
        System.out.println(cnt);
    }    
}
