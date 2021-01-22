/*
	21.01.22
	BOJ : 1504 특별한 최단 경로 (https://www.acmicpc.net/problem/1504)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define num second
#define val first

int n, e;
vector <pii> adj[801];
int dist[801];
priority_queue <pii, vector<pii>, greater<pii>> q;

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
}

void dijk(int start) {
	init();
	q.push({ 0,start });
	while (!q.empty()) {
		auto cur = q.top(); q.pop();

		if (dist[cur.num] < cur.val) continue;

		dist[cur.num] = cur.val;

		for (int i = 0; i < adj[cur.num].size(); i++) {
			auto nxt = adj[cur.num][i];

			if (dist[nxt.num] > cur.val + nxt.val) {
				q.push({ cur.val + nxt.val ,nxt.num });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n >> e;
	while (e--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c,b });
		adj[b].push_back({ c,a });
	}

	int vertex1, vertex2;
	cin >> vertex1 >> vertex2;
	
	int vertex_dist;

	long long int dist1=0;
	// 1 -> vertex1 -> vertex2 -> n의 경우
	dijk(1);
	dist1 += dist[vertex1];
	dijk(vertex1);
	vertex_dist = dist[vertex2];
	dist1 += dist[vertex2];
	dijk(vertex2);
	dist1 += dist[n];


	long long int dist2 = 0;
	// 1 -> vertex2 -> vertex1 -> n의 경우
	dijk(1);
	dist2 += dist[vertex2];
	dist2 += vertex_dist;
	dijk(vertex1);
	dist2 += dist[n];
	
	long long int ans = min(dist1, dist2);
	if (ans >= INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
	return 0;
}