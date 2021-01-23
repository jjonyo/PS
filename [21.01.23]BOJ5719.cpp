/*
	21.01.23
	BOJ : 5719 거의 최단 경로  (https://www.acmicpc.net/problem/5719)
	다익스트라 
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define num second
#define val first

int n, m;
vector <pii> adj[501];
vector <int> trace[501];
int p[501][501];
int dist[501];
priority_queue <pii, vector<pii>, greater<pii>> pq;
queue <int> q;
int start, dest;

void distInit() {
	for (int i = 0; i < n; i++) {
		dist[i] = INT_MAX;
	}
}

void clear() {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		trace[i].clear();
	}

	memset(p, 0x00, sizeof(p));
}

void remove() {
	q.push(dest);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < trace[cur].size(); i++) {
			int prev = trace[cur][i];

			if (p[prev][cur] == 0) continue;

			if (dist[cur] == dist[prev] + p[prev][cur]) {
				p[prev][cur] = 0;
			}
			q.push(prev);
		}
	}
}

void dijk() {
	distInit();
	dist[start] = 0;
	pq.push({ 0,start });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.num] < cur.val) continue;

		for (int i = 0; i < adj[cur.num].size(); i++) {
			auto nxt = adj[cur.num][i];
			if (p[cur.num][nxt.num] == 0) continue;
			int newDist = cur.val + p[cur.num][nxt.num];

			if (dist[nxt.num] > newDist) {
				dist[nxt.num] = newDist;
				trace[nxt.num].clear();
				trace[nxt.num].push_back(cur.num);
				pq.push({ newDist,nxt.num });
			}
			else if (dist[nxt.num] == newDist) {
				trace[nxt.num].push_back(cur.num);
			}		
				
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		cin >> start >> dest;

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ c,b });
			p[a][b] = c;
		}

		dijk();
		remove();
		dijk();

		if (dist[dest] == INT_MAX) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[dest]<<'\n';
		}
		
		clear();
	}
	return 0;
}