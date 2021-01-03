/*
	21.01.03
	BOJ : 17837 새로운 게임 2 (https://www.acmicpc.net/problem/17837)
	구현
*/
#include <bits/stdc++.h>
using namespace std;

typedef struct info {
	int r;
	int c;
	int dir;
}info;
int N, K;
int board[14][14];
vector <int> item[14][14];
vector <info> idx;

int dx[5] = {0, 0,0,-1,1 };
int dy[5] = {0, 1,-1,0,0 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0) {
				board[i][j] = -1;
			}else
				cin >> board[i][j];
		}
	}

	idx.push_back({ 0,0,0 });
	for (int i = 1; i <= K; i++) {
		int r, c, dir;
		cin >> r >> c >> dir;
		idx.push_back({ r,c,dir });
		item[r][c].push_back(i);
	}

	int turn = 0;
	int end = 0;
	int blue = 0;
	while (true) {
		turn++;
		if (turn >= 1000) break;
		for (int i = 1; i <= K; i++) {
			auto cur = idx[i];

			int nr = cur.r + dx[cur.dir];
			int nc = cur.c + dy[cur.dir];

			if (board[nr][nc] == 2 || (nr<1 || nc <1 || nr>N || nc >N)) {
				if (blue) {
					blue = 0;
					continue;
				}
					
				if (cur.dir == 1) {
					idx[i].dir = 2;
				}
				else if (cur.dir == 2) {
					idx[i].dir = 1;
				}
				else if (cur.dir == 3) {
					idx[i].dir = 4;
				}
				else if (cur.dir == 4) {
					idx[i].dir = 3;
				}

				if (!blue) {
					i--;
					blue = 1;
				}
			}else if (board[nr][nc] == 0) { //white
				blue = 0;
				int size = item[cur.r][cur.c].size();
				vector <int> remain;
				vector <int> add;

				int check = 0;
				for (int j = 0; j < size; j++) {
					if (i == item[cur.r][cur.c][j]) {
						check = 1;
					}
					if (!check) {
						remain.push_back(item[cur.r][cur.c][j]);
					}
					else {
						add.push_back(item[cur.r][cur.c][j]);
					}
				}

				item[cur.r][cur.c].clear();
				for (int j = 0; j < remain.size(); j++) {
					item[cur.r][cur.c].push_back(remain[j]);
				}

				for (int j = 0; j < add.size(); j++) {
					item[nr][nc].push_back(add[j]);
					idx[add[j]].r = nr;
					idx[add[j]].c = nc;
				}

				if (item[nr][nc].size() >= 4) {
					end = 1;
				}
			}
			else if (board[nr][nc] == 1) {
				blue = 0;
				int size = item[cur.r][cur.c].size();
				vector <int> remain;
				vector <int> add;

				int check = 0;
				for (int j = 0; j < size; j++) {
					if (i == item[cur.r][cur.c][j]) {
						check = 1;
					}
					if (!check) {
						remain.push_back(item[cur.r][cur.c][j]);
					}
					else {
						add.push_back(item[cur.r][cur.c][j]);
					}
				}

				reverse(add.begin(), add.end());

				item[cur.r][cur.c].clear();
				for (int j = 0; j < remain.size(); j++) {
					item[cur.r][cur.c].push_back(remain[j]);
				}

				for (int j = 0; j < add.size(); j++) {
					item[nr][nc].push_back(add[j]);
					idx[add[j]].r = nr;
					idx[add[j]].c = nc;
				}

				if (item[nr][nc].size() >= 4) {
					end = 1;
				}
			}
			

			if (end) {
				cout << turn;
				return 0;
			}
		}
		
	}

	cout << -1;

}

