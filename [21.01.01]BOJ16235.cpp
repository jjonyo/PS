/*
	21.01.01
	BOJ : 16236 나무 재테크 (https://www.acmicpc.net/problem/16235)
	구현, 시뮬레이션
*/

#include <bits/stdc++.h>
using namespace std;

int N,M,K;
int A[11][11] = { 0 };
int Farm[11][11] = { 0 };
vector <int> live[11][11];

int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1, 0, 1,-1,1,-1,0,1 };

bool cmp(int a, int b)
{
	return a < b;
}

void springsummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (live[i][j].size() == 0) continue;

			sort(live[i][j].begin(), live[i][j].end(),cmp);

			int size = live[i][j].size();
			int sum = 0;
			vector <int> live_tree;
			for (int k = 0; k < size; k++) {
				if (Farm[i][j] >= live[i][j][k]) { //양분 섭취
					Farm[i][j] -= live[i][j][k];
					live_tree.push_back(live[i][j][k] + 1);
				}
				else {
					sum += (live[i][j][k] / 2);
				}
			}

			live[i][j].clear();
			for (int k = 0; k < live_tree.size(); k++) {
				live[i][j].push_back(live_tree[k]);
			}
			Farm[i][j] += sum;
		}
	}
}

void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int size = live[i][j].size();
			if (size == 0) continue;

			for (int k = 0; k < size; k++) {
				if (live[i][j][k] % 5 == 0) {
					for (int dir = 0; dir < 8; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
						if (nx <1 || ny< 1 || nx>N || ny>N) continue;
						live[nx][ny].push_back(1);
					}
				}
			}
			
		}
	}
}

void winter() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			Farm[i][j] += A[i][j];
		}
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			Farm[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, age;
		cin >> x >> y >> age;
		live[x][y].push_back(age);
	}

	while (K--) {
		springsummer();
		fall();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += live[i][j].size();
		}
	}

	cout << ans;

}

