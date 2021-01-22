/*
	21.01.22
	BOJ : 14567 선수과목 (https://www.acmicpc.net/problem/14567)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int indegree[1001];
vector <int> adj[1001];
int ans[1001];
queue <int> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		indegree[b]++;
	}

	int sem = 1;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}

	while (true) {
		if (q.empty()) break;
		int s = q.size();
		for (int i = 0; i < s; i++) {
			int cur = q.front(); q.pop();
			ans[cur] = sem;
			for (int i = 0; i < adj[cur].size(); i++) {
				int nxt = adj[cur][i];
				indegree[nxt]--;
				if (indegree[nxt] == 0) {
					q.push(nxt);
				}
			}
		}
		sem++;
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}

	return 0;
}