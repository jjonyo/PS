/*
	21.01.23
	BOJ : 2665 미로만들기  (https://www.acmicpc.net/problem/2665)
	다익스트라 
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define num second
#define val first

struct info {
	int r;
	int c;
	int d;
};

struct cmp {
	bool operator() (info& a, info& b) {
		return a.d > b.d;
	}
};

int n;
string board[51];
int dist[51][51];
priority_queue <info, vector<info>, cmp> pq;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	pq.push({ 0,0,0 });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.r][cur.c] < cur.d) continue;

		dist[cur.r][cur.c] = cur.d;

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.r + dx[dir];
			int ny = cur.c + dy[dir];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			int newDist = cur.d;
			if (board[nx][ny] == '0') {
				newDist += 1;
			}

			if (dist[nx][ny] > newDist) {
				pq.push({ nx,ny,newDist });
			}
		}
	}

	cout << dist[n - 1][n - 1];

	return 0;
}