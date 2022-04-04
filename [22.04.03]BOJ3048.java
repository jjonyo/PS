import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.Exception;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.Collections;

class BOJ3048 {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        int N, M;

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        String a, b;
        a = br.readLine();
        b = br.readLine();
        int T = Integer.parseInt(br.readLine());

        List<Ant> list = new ArrayList<>();

        for (int i=a.length() - 1; i>=0; i--)
        {
            list.add(new Ant(a.charAt(i), 0, false));
        }
        for (int i=0; i<b.length(); i++)
        {
            list.add(new Ant(b.charAt(i), 1, false));
        }

        while (T != 0) {
            for (int i=0; i<list.size(); i++) {
                Ant ant = list.get(i);
                if (ant.isMoved) continue;

                if (ant.direction == 0){
                    if (i == list.size() - 1) continue;

                    Ant nextAnt = list.get(i + 1);
                    if (nextAnt.direction == ant.direction) continue;
                    if (nextAnt.isMoved) continue;
                    nextAnt.isMoved = true;
                    ant.isMoved = true;
                    Collections.swap(list, i, i + 1);
                }else if (ant.direction == 1) {
                    if (i == 0) continue;

                    Ant nextAnt = list.get(i - 1);
                    if (nextAnt.direction == ant.direction) continue;
                    if (nextAnt.isMoved) continue;
                    nextAnt.isMoved = true;
                    ant.isMoved = true;
                    Collections.swap(list, i, i - 1);
                }
            }

            //isMoved 초기화
            for (Ant ant : list) {
                ant.isMoved = false;
            }
            T--;
        }

        StringBuilder ans = new StringBuilder();

        for (Ant ant : list){
            ans.append(ant.c);
        }

        System.out.println(ans.toString());
    }

    public static class Ant {
        public char c;
        public int direction;
        public boolean isMoved;

        public Ant(char c, int direction, boolean isMoved) {
            this.c = c;
            this.direction = direction;
            this.isMoved = isMoved;
        }
    }
}
