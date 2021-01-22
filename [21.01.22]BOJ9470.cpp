/*
	21.01.22
	BOJ : 9470 Strahler 순서 (https://www.acmicpc.net/problem/9470)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;

int tc;
int k, m, p;
vector <int> adj[1001];
int indegree[1001];
int strahler[1001];
pair<int, int> info[1001];
queue <int> q;

void init() {
	for (int i = 1; i <= m; i++) {
		adj[i].clear();
	}

	memset(indegree, 0x00, sizeof(indegree));
	memset(strahler, 0x00, sizeof(strahler));
	memset(info, 0x00, sizeof(info));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	while(tc--) {
		cin >> k >> m >> p;
		int ans = 0;
		for (int i = 0; i < p; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			indegree[b]++;
		}

		
		for (int i = 1; i <= m; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();
			int n = info[cur].first;
			int c = info[cur].second;

			if (c == 1) {
				strahler[cur] = n;
			}
			else {
				strahler[cur] = n + 1;
			}

			ans = max(ans, strahler[cur]);
			for (int i = 0; i < adj[cur].size(); i++) {
				int nxt = adj[cur][i];

				indegree[nxt]--;
				if (indegree[nxt] == 0) {
					q.push(nxt);
				}

				if (info[nxt].first < strahler[cur]) {
					info[nxt].first = strahler[cur];
					info[nxt].second = 1;
				}
				else if (info[nxt].first == strahler[cur]) {
					info[nxt].second += 1;
				}
			}
		}

		cout << k << " " << ans << '\n';
		init();
	}

	return 0;
}