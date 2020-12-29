/*
	20.12.29
	BOJ : 14503 로봇 청소기 (https://www.acmicpc.net/problem/14503)
	구현
*/

#include <iostream>
using namespace std;

int N, M;
int map[51][51];
int vis[51][51];

int dx[4] = { -1,0,1,0, };
int dy[4] = { 0,1,0,-1 };

int curDir;
int cx, cy;

int main() {
	cin >> N >> M;
	cin >> cx >> cy >> curDir;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 1;
	vis[cx][cy] = 1;
	int cnt = 0;
	while (1) {
		int nDir = (curDir + 3) % 4;
		int nx = cx + dx[nDir];
		int ny = cy + dy[nDir];
		cnt++;
		if (map[nx][ny] == 0 && vis[nx][ny] == 0) { //방문하지 않았고 벽이 아닌 경우
			cx = nx;
			cy = ny;
			curDir = nDir;
			vis[nx][ny] = 1;
			ans++;
			cnt = 0;
		}
		else if (cnt < 4 && (map[nx][ny] == 1 || vis[nx][ny] == 1)) { //벽이거나 방문했을경우 방향만 바꿈.
			curDir = nDir;
		}
		else if (cnt == 4) { //네방향 모두 탐색함.
			int bDir = (nDir + 2) % 4;
			int bx = cx + dx[bDir];
			int by = cy + dy[bDir];

			if (map[bx][by] == 1) {
				cout << ans;
				return 0;
			}
			else {
				curDir = nDir;
				cx = bx;
				cy = by;
				cnt = 0;
			}
		}
	}
}