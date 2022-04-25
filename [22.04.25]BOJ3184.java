/*
    2022.04.25
    BOJ : 3184 양 (https://www.acmicpc.net/problem/3184)
    Algorithm : BFS
*/

import java.util.*;
import java.io.*;

public class BOJ3184 {

    static int R,C;
    static char[][] map;
    static boolean[][] vis;
    static int O = 0;
    static int V = 0;

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[250][];
        vis = new boolean[250][250];

        for (int i=0; i<R; i++) {
            map[i] = br.readLine().toCharArray();
        }
    }

    public static void BFS(int r, int c) {
        Queue<Node> Q = new LinkedList<>();
        int[] dx = new int[]{1, -1, 0, 0};
        int[] dy = new int[]{0, 0, 1, -1};

        Q.add(new Node(r, c));
        vis[r][c] = true;

        int v = 0;
        int o = 0;
        while (!Q.isEmpty()) {
            Node cur = Q.poll();
            if (map[cur.r][cur.c] == 'v') v++;
            else if (map[cur.r][cur.c] =='o') o++;

            for (int dir = 0; dir < 4; dir++) {
                Node next = new Node(cur.r + dx[dir], cur.c + dy[dir]);
                if (next.r < 0 || next.c < 0 || next.r >= R || next.c >= C) continue;
                if (vis[next.r][next.c] || map[next.r][next.c] == '#') continue;
                vis[next.r][next.c] = true;
                Q.add(next);
            }
        }

        if (o > v) {
            v = 0;
        } else {
            o = 0;
        }

        V += v;
        O += o;
    }

    public static void main(String[] args) throws IOException {
        input();

        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if (vis[i][j] || map[i][j] == '#') continue;
                BFS(i, j);
            }
        }

        System.out.println(O + " " + V);
    }

    public static class Node {
        int r, c;

        public Node(int r, int c) {
            this.r = r;
            this.c = c;
        }
    }
}