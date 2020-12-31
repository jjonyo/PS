/*
	20.12.30
	BOJ : 14500 테트로미노 (https://www.acmicpc.net/problem/14500)
	브루트포스, 그래프탐색
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[501][501];
bool vis[501][501];
int ans = 0;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void dfs(int r, int c, int cnt,int sum)
{
	cnt += 1;
	sum += board[r][c];
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	if (cnt == 2) {
		vector <pair<int, int>> vc;
		for (int dir = 0; dir < 4; dir++) {
			int nx = r + dx[dir];
			int ny = c + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (vis[nx][ny]) continue;
			vc.push_back({ nx,ny });
		}

		if (vc.size() == 2) {
			ans = max(ans, sum + board[vc[0].first][vc[0].second] + board[vc[1].first][vc[1].second]);
		}
		else if (vc.size() == 3) {
			ans = max(ans, sum + board[vc[0].first][vc[0].second] + board[vc[1].first][vc[1].second]);
			ans = max(ans, sum + board[vc[1].first][vc[1].second] + board[vc[2].first][vc[2].second]);
			ans = max(ans, sum + board[vc[0].first][vc[0].second] + board[vc[2].first][vc[2].second]);
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		int nx = r + dx[dir];
		int ny = c + dy[dir];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (vis[nx][ny]) continue;
	
		vis[nx][ny] = 1;
		dfs(nx, ny, cnt, sum);
		vis[nx][ny] = 0;
	}

}


int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			vis[i][j] = 1;
			dfs(i, j, 0, 0);
			vis[i][j] = 0;
		}
	}

	cout << ans;
}