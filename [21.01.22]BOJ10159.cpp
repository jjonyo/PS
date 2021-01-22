/*
	21.01.22
	BOJ : 10159 저울 (https://www.acmicpc.net/problem/10159)
	플로이드-워셜 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

int adj[101][101];
int adj_rev[101][101];
int n, m;

void floyd(int (*dist)[101]) {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j]) continue;
				
				if (dist[i][k] && dist[k][j]) {
					dist[i][j] = 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		adj[a][b] = 1; //a가 b보다 무겁다.
		adj_rev[b][a] = 1;
	}

	floyd(adj);
	floyd(adj_rev);

	for (int i = 1; i <= n; i++) {
		int ans = 0;
		for (int j = 1; j <= n; j++) {
			ans += adj[i][j];
			ans += adj_rev[i][j];
		}

		cout << n - ans -1<<'\n';
	}


	return 0;
}