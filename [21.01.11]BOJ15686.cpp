/*
	21.01.11
	BOJ : 15686 치킨 배달 (https://www.acmicpc.net/problem/15686)
	백트래킹
*/
#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> chicken;
vector <pair<int, int>> house;
int MAP[52][52] = { 0 };
int selected[15] = { 0 };
bool isUsed[15] = { 0 };
int N, M;
int ans = INT_MAX;
int chickenSize = 0;

void dfs(int n,int cnt) {
	if (cnt == M) {
		int houseSize = house.size();
		int sum = 0;

		for (int i = 0; i < houseSize; i++) {
			auto houseCurrent = house[i];
			int dist = INT_MAX;
			for (int j = 0; j < M; j++) {
				auto chickenCurrent = chicken[selected[j]];
				dist = min(dist, abs(chickenCurrent.first - houseCurrent.first) + abs(chickenCurrent.second - houseCurrent.second));
			}
			sum += dist;
		}
		ans = min(ans, sum);
		return;
	}

	for (int i = n; i < chickenSize; i++) {
		if (isUsed[i]) continue;
		isUsed[i] = 1;
		selected[cnt] = i;
		dfs(i, cnt + 1);
		isUsed[i] = 0;
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) {
				chicken.push_back({ i,j });
			}
			else if (MAP[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}
	chickenSize = chicken.size();
	dfs(0, 0);
	cout << ans;

	return 0;
}