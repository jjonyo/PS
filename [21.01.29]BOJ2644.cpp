/*
	21.01.29
	BOJ : 2644 촌수계산 (https://www.acmicpc.net/problem/2644)
	BFS
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[101];
int dist[101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int n;
	cin >> n;
	int start, dest;
	cin >> start >> dest;

	int m;
	cin >> m;

	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	queue <int> q;
	memset(dist, 0xff, sizeof(dist));

	q.push(start);
	dist[start] = 0;

	int ans = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == dest) {
			ans = dist[cur];
			break;
		}

		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			if (dist[nxt] != -1) continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	
	if (ans) {
		cout << ans;
	}else
		cout << -1;
	return 0;
}