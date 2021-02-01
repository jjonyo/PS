/*
	21.02.01
	BOJ : 1854 K번째 최단경로 찾기 (https://www.acmicpc.net/problem/1854)
	다익스트라 / 우선순위 큐
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define val first
#define num second

int n, m, k;
vector <pii> adj[1001];
priority_queue <int, vector<int>, less<int>> dist[1001];
priority_queue <pii, vector<pii>, greater<pii>> pq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;

	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ c,b });
	}

	dist[1].push(0);
	pq.push({ 0,1 });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		for (int i = 0; i < adj[cur.num].size(); i++) {
			auto nxt = adj[cur.num][i];

			int nDist = cur.val + nxt.val;
			if (dist[nxt.num].size() < k) {
				dist[nxt.num].push(nDist);
				pq.push({ nDist,nxt.num });
			}
			else {
				if (dist[nxt.num].top() > nDist) {
					dist[nxt.num].pop();
					dist[nxt.num].push(nDist);
					pq.push({ nDist,nxt.num });
				}
			}	
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) {
			cout << -1 << '\n';
		}
		else {
			cout << dist[i].top() << '\n';
		}
	}
	

	return 0;
}