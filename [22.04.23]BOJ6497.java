/*
	2022.04.23
	BOJ : 6497 전력난 (https://www.acmicpc.net/problem/6497)
	Algorithm : 크루스칼
*/
import java.util.*;
import java.io.*;

public class BOJ6497 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());
            if (N == 0 && M == 0) break;

            ArrayList<Edge> list = new ArrayList<>();
            int sum = 0;
            for (int i=0; i<M; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                int z = Integer.parseInt(st.nextToken());
                list.add(new Edge(x, y, z));
                sum += z;
            }

            //sort
            Collections.sort(list);

            //크루스칼 알고리즘 수행
            int[] parent = new int[N];

            //init
            for (int i=0; i<N; i++) {
                parent[i] = i;
            }

            int ans = 0;
            for (Edge edge : list) {
                if (find(parent, edge.a) == find(parent, edge.b)) continue;

                union(parent, edge.a, edge.b);
                ans += edge.w;
            }

            System.out.println(sum - ans);
        }
    }

    public static int find(int[] parent, int num) {
        if (parent[num] == num) return num;

        parent[num] = find(parent, parent[num]);
        return parent[num];
    }

    public static void union(int[] parent, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);

        parent[pa] = pb;
    }

    public static class Edge implements Comparable<Edge> {
        int a;
        int b;
        int w;

        public Edge(int a, int b, int w) {
            this.a = a;
            this.b = b;
            this.w = w;
        }

        @Override
        public String toString() {
            return a + " " + b + " " + w;
        }

        @Override
        public int compareTo(Edge e) {
            return this.w - e.w;
        }
    }
}
