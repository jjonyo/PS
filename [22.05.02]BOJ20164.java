/*
    2022.05.02
    BOJ : 20164 홀수 홀릭 호석 (https://www.acmicpc.net/problem/20164)
    Algorithm : 완전탐색
*/

import java.io.*;

public class BOJ20164 {
    
    static String n;
    static int max = 0;
    static int min = Integer.MAX_VALUE;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        n = br.readLine();
    }

    static int isOdd(char n) {
        return (n - '0') % 2 == 0 ? 0 : 1; 
    }

    static int countOdd(String num) {
        int count = 0;

        for (int i=0; i<num.length(); i++) {
            count += isOdd(num.charAt(i));
        }

        return count;
    }

    static void solve(String num, int count) {
        //홀수의 개수를 계산한다.
        count += countOdd(num);

        if (num.length() == 1) {
            max = Math.max(max, count);
            min = Math.min(min, count);
        } else if (num.length() == 2) {
            int sum = num.charAt(0) - '0' + num.charAt(1) - '0';
            
            solve(Integer.toString(sum), count);
        } else {
            for (int i=0; i<num.length() - 2; i++) {
                for (int j=i + 1; j < num.length() - 1; j++) {
                    int first = Integer.parseInt(num.substring(0, i + 1));
                    int second = Integer.parseInt(num.substring(i + 1, j + 1));
                    int third = Integer.parseInt(num.substring(j + 1, num.length()));

                    int sum = first + second + third;
                    solve(Integer.toString(sum), count);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        solve(n, 0);

        System.out.println(min + " " + max);
    }
}