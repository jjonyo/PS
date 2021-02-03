/*
	21.02.03
	BOJ : 1865 웜홀 (https://www.acmicpc.net/problem/1865)
	벨만포드 알고리즘
*/
#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define MAX 1000000000
int tc;
int n, m, w;

vector <pii> adj[505];
int dist[505];

void init() {
	for (int i = 1; i <= n; i++) {
		dist[i] = MAX;
	}
}

void clear() {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}
}

bool bellman() {

	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int cur = 1; cur <= n; cur++) {
			for (int j = 0; j < adj[cur].size(); j++) {
				auto nxt = adj[cur][j];

				int nDist = dist[cur] + nxt.second;
				if (dist[nxt.first] > nDist) {
					dist[nxt.first] = nDist;
					if (i == n) return true;
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;

	while (tc--) {
		cin >> n >> m >> w;
		init();

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}

		for (int i = 0; i < w; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].push_back({ b,-c });
		}

		bool isCycle = bellman();
		
		cout << (isCycle ? "YES\n" : "NO\n");
		
		clear();
	}
	
	
	return 0;
}