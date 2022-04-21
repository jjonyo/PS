/*
	2022.04.22
	BOJ : 15829 Hashing (https://www.acmicpc.net/problem/15829)
	Algorithm : 수학
*/
import java.util.Scanner;

public class BOJ15829 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int L = sc.nextInt();
        sc.nextLine();
        String word = sc.nextLine();

        int r = 31;
        int M = 1234567891;

        long ans = 0;
        for (int i=0; i< L; i++) {
            char c = word.charAt(i);
            int num = c - 'a' + 1;
            long pow = 1;
            for (int j = 0; j < i; j++) {
                pow *= r;
                pow %= M;
            }
            ans += num * pow % M;
            ans %= M;
        }

        System.out.println(ans);
    } 
}
