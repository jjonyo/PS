/*
	21.01.22
	BOJ : 1613 역사 (https://www.acmicpc.net/problem/1613)
	플로이드-워셜 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

int adj[401][401];
int n, k, s;

void floyd(int (*dist)[401]) {

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
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

	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;

		adj[a][b] = 1;
	}

	floyd(adj);

	cin >> s;

	while (s--) {
		int a, b;
		cin >> a >> b;

		if (adj[a][b] == 0 && adj[b][a] == 0) {
			cout << 0;
		}
		else if (adj[a][b]) {
			cout << -1;
		}
		else if (adj[b][a]) {
			cout << 1;
		}

		cout << '\n';
	}

	return 0;
}