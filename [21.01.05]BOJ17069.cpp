/*
	21.01.05
	BOJ : 17069 파이프 옮기기 2 (https://www.acmicpc.net/problem/17069)
	동적계획법
*/
#include <bits/stdc++.h>
using namespace std;

int board[35][35];
long long int dp[35][35][3];
int N;

long long int go(int r, int c, int dir) {
	if (r == N && c == N) {
		return 1;
	}
	if (dp[r][c][dir]) {
		return dp[r][c][dir];
	}

	dp[r][c][dir] = 0;
	switch (dir) {
	case 0:
	{
		if (board[r][c + 1] == 0) {
			dp[r][c][dir] += go(r, c + 1, 0);
		}

		if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0) {
			dp[r][c][dir] += go(r + 1, c + 1, 1);
		}

		break;
	}
	case 1: {
		if (board[r][c + 1] == 0) {
			dp[r][c][dir] += go(r, c + 1, 0);
		}
		if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0) {
			dp[r][c][dir] += go(r + 1, c + 1, 1);
		}
		if (board[r + 1][c] == 0) {
			dp[r][c][dir] += go(r + 1, c, 2);
		}
		break;
	}
	case 2: {
		if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0) {
			dp[r][c][dir] += go(r + 1, c + 1, 1);
		}

		if (board[r + 1][c] == 0) {
			dp[r][c][dir] += go(r + 1, c, 2);
		}

		break;
	}
	}

	return dp[r][c][dir];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	

	cin >> N;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			if (i == 0 || j == 0 || i > N || j > N) {
				board[i][j] = 1;
			}
			else
				cin >> board[i][j];
		}
	}

	cout << go(1, 2, 0);

}