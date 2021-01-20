/*
	21.01.20
	BOJ : 11657 타임머신 (https://www.acmicpc.net/problem/11657)
	벨만포드 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define plint pair<ll,ll>
int n, m;
vector <plint> adj[501];
ll dist[501];
bool isCycle;

bool bellman_ford() {
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[j] == INT_MAX) continue;
			for (int k = 0; k < adj[j].size(); k++) {
				int nxt = adj[j][k].first;
				if (dist[nxt] > dist[j] + adj[j][k].second) {
					dist[nxt] = dist[j] + adj[j][k].second;

					if (i == n) {
						return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		adj[a].push_back({ b,c });
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}

	isCycle = bellman_ford();

	if (isCycle) {
		cout << -1;
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INT_MAX) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}

	return 0;
}