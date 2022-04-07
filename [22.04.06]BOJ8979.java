import java.io.*;
import java.util.*;

class BOJ8979 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine(), " ");

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        Country[] countires = new Country[N + 1];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int num = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            countires[num] = new Country(g, s, b);
        }

        int ans = 0;
        for (int i = 1; i <= N; i++) {
            if (i == K)
                continue;

            if (compare(countires[i], countires[K])) {
                ans++;
            }
        }

        System.out.println(ans + 1);
    }

    static boolean compare(Country a, Country b) {
        if (a.gold > b.gold) {
            return true;
        } else if (a.gold == b.gold) {
            if (a.silver > b.silver) {
                return true;
            } else if (a.silver == b.silver) {
                if (a.bronze > b.bronze) {
                    return true;
                }
            }
        }
        return false;
    }

    static class Country {
        int gold;
        int silver;
        int bronze;

        Country(int gold, int silver, int bronze) {
            this.gold = gold;
            this.silver = silver;
            this.bronze = bronze;
        }
    }

}