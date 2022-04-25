/*
    2022.04.25
    BOJ : 18404 현명한 나이트 (https://www.acmicpc.net/problem/18404)
    Algorithm : BFS
*/

import java.util.*;
import java.io.*;

public class BOJ18404 {

    static int N, M;
    static Node[] idx;
    static Node night;
    static boolean[][] vis;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        night = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

        idx = new Node[M];
        for (int i=0; i<M; i++) {
            st = new StringTokenizer(br.readLine());

            idx[i] = new Node(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        vis = new boolean[N + 1][N + 1];
    }

    public static void isTarget(Node cur) {
        for (int i=0; i<M; i++) {
            Node node = idx[i];

            if (node.r == cur.r && node.c == cur.c) {
                node.ans = Math.min(node.ans, cur.count);
                break;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        input();

        Queue<Node> Q = new LinkedList<>();
        int[] dr = new int[]{-2, -1, 1, 2, -2, -1, 1, 2};
        int[] dc = new int[]{1, 2, 2, 1, -1, -2, -2, -1};

        Q.add(night);
        vis[night.r][night.c] = true;

        while (!Q.isEmpty()) {
            Node cur = Q.poll();

            isTarget(cur);

            //다음위치를 계산한다.
            for (int dir=0; dir<8; dir++) {
                int nr = cur.r + dr[dir];
                int nc = cur.c + dc[dir];
                if (nr < 0 || nc < 0 || nr > N || nc > N) continue;
                if (vis[nr][nc]) continue;
                Node node = new Node(nr,nc);
                node.count = cur.count + 1;
                Q.add(node);
                vis[nr][nc] = true;
            }
        }

        StringBuilder sb = new StringBuilder();
        for (int i=0;i<M;i++) {
            Node node = idx[i];

            sb.append(node.ans).append(" ");
        }

        System.out.println(sb.toString());
    }

    public static class Node {
        int r, c, count, ans;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
            this.count = 0;
            this.ans = Integer.MAX_VALUE;
        }

        public void setAns(int ans) {
            this.ans = ans;
        }
    }
}