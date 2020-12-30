/*
	20.12.30
	BOJ : 14890 경사로 (https://www.acmicpc.net/problem/14890)
	구현
*/

#include <iostream>
using namespace std;

int N, L;
int map[101][101];
bool vis[101];

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	int ans = 0;

	//행 탐색
	for (int i = 0; i < N; i++) {
		int check = 1;
		int prev = map[i][0];
		for (int n = 0; n < N; n++)
			vis[n] = 0;

		for (int j = 1; j < N; j++) {
			if (map[i][j] > prev) { //
				if (j - L < 0 || abs(map[i][j]-prev) != 1) { //범위 벗어나거나 차이가 2 이상이면 경사로 못놓음
					check = 0;
					break;
				}

				int st = j - L;
				int value = map[i][st];
				bool isSame = 1;
				for (int k = st; k < j; k++) {
					if (map[i][k] != value || vis[k]) {
						isSame = 0;
						break;
					}
				}

				if (st - 1 >=0 && map[i][st - 1] > value) {
					isSame = 0;
				}


				if (!isSame) {
					check = 0;
					break;
				}
				else {
					vis[j-1] = 1;
				}
			}
			else if (map[i][j] < prev) {
				if (j + L -1 >= N || abs(map[i][j] - prev) != 1) { //범위 벗어나거나 차이가 2 이상이면 경사로 못놓음
					check = 0;
					break;
				}

				int ed = j + L - 1;
				int value = map[i][j];
				bool isSame = 1;
				for (int k = j; k <= ed; k++) {
					if (map[i][k] != value || vis[k]) {
						isSame = 0;
						break;
					}
				}

				if (ed +1  <N && map[i][ed + 1] > value) {
					isSame = 0;
				}

				if (!isSame) {
					check = 0;
					break;
				}
				else {
					vis[ed] = 1;
				}
			}
			prev = map[i][j];
		}

		if (check)
		{
			ans++;
		}
	}

	//열 탐색
	for (int i = 0; i < N; i++) {
		int check = 1;
		int prev = map[0][i];
		for (int n = 0; n < N; n++)
			vis[n] = 0;
		for (int j = 1; j < N; j++) {
			if (map[j][i] > prev) { //
				if (j - L < 0 || abs(map[j][i] - prev) != 1) { //범위 벗어나거나 차이가 2 이상이면 경사로 못놓음
					check = 0;
					break;
				}

				int st = j - L;
				int value = map[st][i];
				bool isSame = 1;
				for (int k = st; k < j; k++) {
					if (map[k][i] != value || vis[k]) {
						isSame = 0;
						break;
					}
				}

				if (st - 1 >= 0 && map[st-1][i] > value) {
					isSame = 0;
				}

				if (!isSame) {
					check = 0;
					break;
				}
				else {
					vis[j-1] = 1;
				}
			}
			else if (map[j][i] < prev) {
				if (j + L - 1 >= N || abs(map[j][i] - prev) != 1) { //범위 벗어나거나 차이가 2 이상이면 경사로 못놓음
					check = 0;
					break;
				}

				int ed = j + L - 1;
				int value = map[j][i];
				bool isSame = 1;
				for (int k = j; k <= ed; k++) {
					if (map[k][i] != value ||vis[k]) {
						isSame = 0;
						break;
					}
				}

				if (ed + 1 < N && map[ed + 1][i] > value) {
					isSame = 0;
				}

				if (!isSame) {
					check = 0;
					break;
				}
				else {
					vis[ed] = 1;
				}
			}
			prev = map[j][i];
		}

		if (check)
		{
			ans++;
		}
	}

	cout << ans;
}