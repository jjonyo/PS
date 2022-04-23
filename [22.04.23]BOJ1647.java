/*
	2022.04.23
	BOJ : 1647 도시분할계획 (https://www.acmicpc.net/problem/1647)
	Algorithm : 크루스칼
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ1647 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList<Edge> list = new ArrayList<>();

        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            int C = Integer.parseInt(st.nextToken());

            list.add(new Edge(A, B, C));
        }

        Collections.sort(list);

        int[] parent = new int[N + 1];
        //부모를 자기 자신으로 초기화
        for (int i=1; i<=N; i++) {
            parent[i] = i;
        }


        int ans = 0;
        int mx = 0;
        for (Edge e : list) {
            //e.a랑 e.b가 연결되어 있는지 확인
            if (find(parent, e.a) == find(parent, e.b)) continue;

            mx = Math.max(mx, e.w);
            union(parent, e.a, e.b);
            ans += e.w;
        }

        System.out.println(ans - mx);
    }

    public static int find(int[] parent, int num) {
        if (parent[num] == num) return num;

        parent[num] = find(parent, parent[num]);
        return parent[num];
    }

    public static void union(int[] parent, int a, int b) {
        int pa = find(parent, a);
        int pb = find(parent, b);

        if (pa == pb) return;
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
        public int compareTo(Edge e) {
            return this.w - e.w;
        }
    }
}
