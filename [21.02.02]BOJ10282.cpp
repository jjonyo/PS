/*
	21.02.02
	BOJ : 10282 해킹 (https://www.acmicpc.net/problem/10282)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>

using namespace std;
#define pii pair<int,int>
#define val first
#define num second

int t;
int n, d, c;

vector <pii> adj[10001];
priority_queue <pii, vector<pii>, greater<pii>> pq;
int dist[10001];

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
}

void clear() {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	while (t--) {
		cin >> n >> d >> c;
		
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			adj[b].push_back({ s,a });
		}

		init();
		pq.push({ 0,c });

		while (!pq.empty()) {
			auto cur = pq.top(); pq.pop();

			if (dist[cur.num] < cur.val) continue;

			dist[cur.num] = cur.val;

			for (int i = 0; i < adj[cur.num].size(); i++) {
				auto nxt = adj[cur.num][i];

				int nDist = dist[cur.num] + nxt.val;
				if (dist[nxt.num] > nDist) {
					pq.push({ nDist,nxt.num });
				}
			}
		}

		int ans = 0;
		int mx = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INT_MAX) {
				ans++;
				mx = max(mx, dist[i]);
			}
		}

		cout << ans << " " <<mx << '\n';
		clear();
	}
	
	return 0;
}