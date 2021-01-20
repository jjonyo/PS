/*
	21.01.20
	BOJ : 3860 할로윈 묘지 (https://www.acmicpc.net/problem/3860)
	벨만포드 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct info {
	int r;
	int c;
	int t;
};
int w, h ,g, e;
int board[31][31];
info hole[31][31];
ll dist[32][32];
bool isCycle;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

void init() {
	memset(board, 0, sizeof(board));
	memset(hole, 0, sizeof(hole));
}

bool bellman() {
	//거리 초기화
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	dist[0][0] = 0; //시작점의 거리는 0

	for (int i = 0; i < w * h - g; i++) { //전체 크기에서 묘지의 갯수를 뺀게 정점의 갯수.
		for (int j = 0; j < w; j++) { //행
			for (int k = 0; k < h; k++) { //열
				//아직 방문한적이 없는 정점이나, 묘지이거나, 목적지인경우 거리 update하지 않음.
				if (dist[j][k] == INT_MAX || board[j][k] == 1 || (j == w - 1 && k == h - 1)) continue;

				if (board[j][k] != 2) { //구멍이 아닐경우 (잔디)
					for (int dir = 0; dir < 4; dir++) { //인접한 네 방향에 대해서 탐색
						int nx = j + dx[dir];
						int ny = k + dy[dir];
						if (nx < 0 || ny < 0 || nx >= w || ny >= h || board[nx][ny] == 1) continue; //범위응 벗어나거나 묘지일경우 스킵
						if (dist[nx][ny] > dist[j][k] + 1) {
							dist[nx][ny] = dist[j][k] + 1;
							if (i == w * h - g - 1) { //이때 업데이트가 이루어지면 음의사이클 존재
								return true;
							}
						}
					}
				}
				else {
					//현재 구멍의 다음 이동위치 정보받아서
					int nx = hole[j][k].r;
					int ny = hole[j][k].c;
					int nt = hole[j][k].t;

					if (dist[nx][ny] > dist[j][k] + nt) { 
						dist[nx][ny] = dist[j][k] + nt; //거리 업데이트
						if (i == w * h - g - 1) {
							return true;
						}
					}
				}
			}
		}
	}

	return false;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> h >> w;
		if (h + w == 0) break;
		init();

		cin >> g;
		for (int i = 0; i < g; i++) {
			int r, c;
			cin >> c >> r;
			board[r][c] = 1; //잔디일경우 board에 1로 표기
		}

		cin >> e;

		for (int i = 0; i < e; i++) {
			int x1, x2, y1, y2, t;
			cin >> y1 >> x1 >> y2 >> x2 >> t;
			board[x1][y1] = 2; //들어가는 구멍일경우 2로 표기
			hole[x1][y1] = { x2,y2,t }; //정보 넣기
		}

		isCycle = bellman();

		if (isCycle) {
			cout << "Never\n";
		}
		else {
			if (dist[w - 1][h - 1] == INT_MAX) {
				cout << "Impossible\n";
			}
			else {
				cout << dist[w - 1][h - 1] << '\n';
			}
		}
	}

	return 0;
}