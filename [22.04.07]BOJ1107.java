import java.util.Scanner;

public class BOJ1107 {
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String N = Integer.toString(sc.nextInt());
        int M = sc.nextInt();
        boolean[] isAble = new boolean[10];
        for (int i = 0; i < 10; i++) {
            isAble[i] = true;
        }

        for (int i = 0; i < M; i++) {
            isAble[sc.nextInt()] = false;
        }

        for (int i = 0; i < 10; i++) {
            if (!isAble[i])
                continue;
            solve(i, N, isAble);
        }

        ans = Math.min(ans, Math.abs(100 - Integer.parseInt(N)));
        System.out.println(ans);
    }

    static void solve(int num, String N, boolean[] isAble) {
        String numString = Integer.toString(num);
        int diff = Math.abs(num - Integer.parseInt(N));
        ans = Math.min(ans, diff + numString.length());
        if (numString.length() >= N.length() + 1) {
            return;
        }

        for (int i = 0; i < 10; i++) {
            if (!isAble[i])
                continue;
            if (num == 0 && i == 0)
                continue;
            int nextNum = num * 10 + i;
            solve(nextNum, N, isAble);
        }
    }
}
