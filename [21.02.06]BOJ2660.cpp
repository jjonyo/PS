/*
	21.02.06
	BOJ : 2660 회장뽑기 (https://www.acmicpc.net/problem/2660)
	BFS
*/
#include <bits/stdc++.h>

using namespace std;

#define MAX 1e9

int n;
int adj[51][51];
int dist[51][51];
int score[51];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = MAX;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}

	init();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i==j || !adj[i][j]) continue;
			queue<pair<int, int>> q;
			q.push({ j,1 });
			while (!q.empty()) {
				auto cur = q.front(); q.pop();
				if (cur.second > dist[i][cur.first] || cur.first == i) continue;
				dist[i][cur.first] = cur.second;

				for (int k = 1; k <= n; k++) {
					if (adj[cur.first][k]) {
						q.push({ k,cur.second + 1 });
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int mx = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX) continue;
			mx = max(mx, dist[i][j]);
		}
		score[i] = mx;
	}

	int mn = MAX;
	for (int i = 1; i <= n; i++) {
		mn = min(score[i], mn);
	}

	vector<int>ans;
	for (int i = 1; i <= n; i++) {
		if (score[i] == mn) ans.push_back(i);
	}

	cout << mn << " " << ans.size() << '\n';
	for (auto v : ans) {
		cout << v << " ";
	}

	
	return 0;
}