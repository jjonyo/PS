/*
	21.02.02
	BOJ : 17836 공주님을 구해라! (https://www.acmicpc.net/problem/17836)
	BFS
*/
#include <bits/stdc++.h>

using namespace std;
struct info {
	int r;
	int c;
	int s;
};
#define pii pair<int,int>
int board[101][101];
int dist[101][101][2];

int n, m, t;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j][0] = INT_MAX;
			dist[i][j][1] = INT_MAX;
		}
	}

	queue <info> q;

	dist[1][1][0] = 0;
	q.push({ 1,1,0});

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		if (dist[cur.r][cur.c][cur.s] > t) continue;
		if (cur.r == n && cur.c == m) break;

		if (board[cur.r][cur.c] == 2) {
			dist[cur.r][cur.c][1] = dist[cur.r][cur.c][0];
			cur.s = 1;
		}

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.r + dx[dir];
			int ny = cur.c + dy[dir];
			if (nx < 1 || ny < 1 || nx >n || ny>m) continue;
			if (dist[nx][ny][cur.s] != INT_MAX) continue;
			if (cur.s == 0 && board[nx][ny] == 1) continue;

			dist[nx][ny][cur.s] = dist[cur.r][cur.c][cur.s] + 1;
			q.push({ nx,ny,cur.s });
		}
	}

	int ans = min(dist[n][m][0], dist[n][m][1]);

	if (ans == INT_MAX) {
		cout << "Fail";
	}
	else {
		cout << ans;
	}

	
	return 0;
}