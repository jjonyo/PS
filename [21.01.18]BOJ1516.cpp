/*
	21.01.18
	BOJ : 1516 게임 개발 (https://www.acmicpc.net/problem/1516)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int index;
	int time;
};

int N;
vector <int> adj[501];
int indegree[501];
int beforeMax[501];
int Time[501];
int ans[501];

queue <int> Q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int cur = i;
		int t;
		cin >> t;

		Time[cur] = t;

		while (true) {
			int input;
			cin >> input;
			if (input == -1) break;
			adj[input].push_back(cur);
			indegree[cur]++;
		}
	}

	fill(ans, ans + N + 1, INT_MAX);

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
	}

	while (!Q.empty()) {
		int cur = Q.front(); Q.pop();

		//current 처리
		ans[cur] = beforeMax[cur] + Time[cur];

		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			indegree[nxt]--;
			beforeMax[nxt] = max(beforeMax[nxt], ans[cur]);
			if (indegree[nxt] == 0) {
				Q.push(nxt);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}