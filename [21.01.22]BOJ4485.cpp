/*
	21.01.22
	BOJ : 4485 녹색 옷 입은 애가 젤다지? (https://www.acmicpc.net/problem/4485)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int r, c;
};

#define pii pair<int,info>

struct cmp {
	bool operator() (pii& a, pii& b) {
		return a.first > b.first;
	}
};

int n;
int board[126][126];
int dist[126][126];
priority_queue<pii, vector<pii>, cmp> q;



int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INT_MAX;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc = 0;
	while (true) {
		cin >> n;
		if (n == 0) break;
		init();

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> board[i][j];
			}
		}

		q.push({ board[1][1],{1,1} });
		
		while (!q.empty()) {
			auto cur = q.top(); q.pop();
			auto rc = cur.second;
			if (dist[rc.r][rc.c] < cur.first) continue;

			dist[rc.r][rc.c] = cur.first;

			for (int dir = 0; dir < 4; dir++) {
				int nr = rc.r + dx[dir];
				int nc = rc.c + dy[dir];
				if (nr <1 || nc<1 || nr>n || nc>n) continue;
				int newDist = cur.first + board[nr][nc];
				if (dist[nr][nc] > newDist) {
					q.push({ newDist,{nr,nc} });
				}
			}
		}
		cout << "Problem "<<++tc<<": "<<dist[n][n]<<'\n';
	}
	return 0;
}