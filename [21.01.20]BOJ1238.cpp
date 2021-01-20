/*
	21.01.20
	BOJ : 1238 파티 (https://www.acmicpc.net/problem/1238)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

#define time first
#define num second
#define pint pair<int,int>

int n, m;
vector <pair<int,int>> adj[1001];
vector <pair<int, int>> adj_rev[1001];
int dist[1001];
int dist_rev[1001];
int x;
priority_queue<pint, vector<pint>, greater<pint>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
		adj_rev[b].push_back({ c,a });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
		dist_rev[i] = INT_MAX;
	}

	//시작점에서 다른 정점으로 갈 수있는 최단거리 구하기.
	pq.push({ 0,x });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.num] < cur.time) continue;

		dist[cur.num] = cur.time;

		for (int i = 0; i < adj[cur.num].size(); i++) {
			auto nxt = adj[cur.num][i];
			int newDist = cur.time + nxt.time;
			if (dist[nxt.num] > newDist) {
				dist[nxt.num] = newDist;
				pq.push({ newDist,nxt.num });
			}
		}
	}
	
	//다른정점에서 시작점으로 갈 수 있는 최단거리 구하기.
	pq.push({ 0,x });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist_rev[cur.num] < cur.time) continue;

		dist_rev[cur.num] = cur.time;

		for (int i = 0; i < adj_rev[cur.num].size(); i++) {
			auto nxt = adj_rev[cur.num][i];
			int newDist = cur.time + nxt.time;
			if (dist_rev[nxt.num] > newDist) {
				dist_rev[nxt.num] = newDist;
				pq.push({ newDist,nxt.num });
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i] + dist_rev[i]);
	}

	cout << ans;
	return 0;
}