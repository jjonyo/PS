/*
	21.01.11
	BOJ : 1103 게임 (https://www.acmicpc.net/problem/1103)
	DFS/DP
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int N, M;
char board[51][51];
bool vis[51][51];
int dp[51][51];

int dfs(int r, int c) {
	if (board[r][c] == 'H' || r < 0 || c < 0 || r >= N || c >= M) { //벗어 났거나 구멍에 빠짐.
		return 0;
	}

	if (vis[r][c]) {
		cout << -1;
		exit(0);
	}

	if (dp[r][c] != -1) {
		//cout << "dp\n";
		return dp[r][c];
	}

	vis[r][c] = true;
	dp[r][c] = 0;
	int number = board[r][c]-'0';
	for (int dir = 0; dir < 4; dir++) {
		int nr, nc;
		if (dir == 0) {
			nr = r - number;
			nc = c;
		}
		else if (dir == 1) {
			nr = r;
			nc = c - number;
		}
		else if (dir == 2) {
			nr = r + number;
			nc = c;
		}
		else if (dir == 3) {
			nr = r;
			nc = c+number;
		}

		dp[r][c]=max(dp[r][c],dfs(nr, nc)+1);
	}
	vis[r][c] = 0;

	return dp[r][c];
}


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) {
		fill(dp[i], dp[i] + M, -1);
	}

	cout<<dfs(0, 0);

	return 0;
}