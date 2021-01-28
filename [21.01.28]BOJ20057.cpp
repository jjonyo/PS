/*
	21.01.28
	BOJ : 20057 마법사 상어와 토네이도  (https://www.acmicpc.net/problem/20057)
	시뮬레이션
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int r, c;
};
int N;
int board[501][501];
int order[501][501];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


info t[4][10] = { {{-2,0},{-1,-1},{-1,0},{-1,1},{0,-2},{1,-1},{1,0},{1,1},{2,0},{0,-1}},
			{{-1,-1},{-1,1},{0,-2},{0,-1},{0,1},{0,2},{1,-1},{1,1},{2,0},{1,0} },
			{{-2,0},{-1,-1},{-1,0},{-1,1},{0,2},{1,-1},{1,0},{1,1},{2,0},{0,1}},
			{{-2,0},{-1,-1},{-1,1},{0,-2},{0,-1},{0,1},{0,2},{1,-1},{1,1},{-1,0}} };

float rate[4][9] = { {0.02,0.1,0.07,0.01,0.05,0.1,0.07,0.01,0.02},
					{0.01,0.01,0.02,0.07,0.07,0.02,0.1,0.1,0.05},
					{0.02,0.01,0.07,0.1,0.05,0.01,0.07,0.1,0.02},
					{0.05,0.1,0.1,0.02,0.07,0.07,0.02,0.01,0.01} };
 
void marking() {
	int last = N * N - 1;

	int i = 1, j = 1;
	int s=1, e = N;
	while (last > 1) {
		for (j; j <= e; j++) {
			order[i][j] = last--;
		}
		j--;
		i++;
		for (i; i <= e; i++) {
			order[i][j] = last--;
		}
		i--;
		j--;
		e--;
		for (j; j >= s; j--) {
			order[i][j] = last--;
		}
		s++;
		i--;
		j++;
		for (i; i >= s; i--) {
			order[i][j] = last--;
		}
		i++;
		j++;
	}
}

bool out(int r, int c) {
	return r < 1 || c <1 || r>N || c >N;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> board[i][j];
		}
	}
    //순서 마킹
	marking();

	info start = { N / 2 + 1,N / 2 };

	int ans = 0;
	queue <pair<info,int>> q;
	q.push({start,0});

	while (!q.empty()) {
		auto cur = q.front().first; 
		int dir = q.front().second;
		q.pop();

		//토네이도 다음 위치로 미리 이동
		for (int d = 0; d < 4; d++) {
			int nr = cur.r + dx[d];
			int nc = cur.c + dy[d];
			if (order[nr][nc] == order[cur.r][cur.c] + 1) {
				q.push({ {nr,nc},d });
				break;
			}
		}

		if (board[cur.r][cur.c] == 0) continue;

		int total = board[cur.r][cur.c];
		int sum = total;
		//모래 이동
		for (int w = 0; w < 9; w++) {
			int nr = cur.r + t[dir][w].r;
			int nc = cur.c + t[dir][w].c;
			int m = total * rate[dir][w];
			if (out(nr,nc)) { //격자의 밖으로 나감
				ans += m;
				sum -= m;
			}
			else {
				board[nr][nc] += m;
				sum -= m;
			}
		}

		//a 처리
		int nr = cur.r + t[dir][9].r;
		int nc = cur.c + t[dir][9].c;
		if (out(nr, nc)) {
			ans += sum;
		}
		else {
			board[nr][nc] += sum;
		}

		board[cur.r][cur.c] = 0;
	}

	cout << ans;
	return 0;
}