/*
	21.02.04
	BOJ : 11779 최소비용 구하기2 (https://www.acmicpc.net/problem/11779)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define val first
#define num second

int n, m;
vector <pii> adj[1001];
priority_queue <pii, vector<pii>, greater<pii>> pq;
int dist[1001];
int path[1001];
int start, dest;

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}

	cin >> start >> dest;
	init();
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.num] < cur.val) continue;

		for (int i = 0; i < adj[cur.num].size(); i++) {
			auto nxt = adj[cur.num][i];
			int nDist = cur.val + nxt.val;
			if (dist[nxt.num] > nDist) {
				dist[nxt.num] = nDist;
				pq.push({ nDist,nxt.num });
				path[nxt.num] = cur.num;
			}
		}
	}

	stack <int> p;
	p.push(dest);
	int cur = dest;
	while (path[cur] != 0) {
		p.push(path[cur]);
		cur = path[cur];
	}
	
	cout << dist[dest] << '\n';
	cout << p.size() << '\n';
	while (!p.empty()) {
		cout << p.top() << " ";
		p.pop();
	}
	return 0;
}