/*
	21.01.22
	BOJ : 음악프로그램 (https://www.acmicpc.net/problem/2623)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;
int indegree[1001];
vector <int> adj[1001];
queue<int> q;
vector<int> ans;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	
	while (m--) {
		int c;
		cin >> c;
		
		int prev;
		cin >> prev;

		for (int i = 0; i < c - 1; i++) {
			int to;
			cin >> to;
			adj[prev].push_back(to);
			indegree[to]++;
			prev = to;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	if (q.empty()) {
		cout << 0;
		return 0;
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];

			indegree[nxt]--;
			if (indegree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}

	if (ans.size() == n) {
		for (auto& v : ans) {
			cout << v << '\n';
		}
	}
	else {
		cout << 0;
	}

	return 0;
}