/*
	21.02.05
	BOJ : 1956 운동 (https://www.acmicpc.net/problem/1956)
	플로이드-와샬 알고리즘
*/
#include <bits/stdc++.h>

using namespace std;

int v, e;
int dist[401][401];

void init() {
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			dist[i][j] = INT_MAX;
		}
	}
}

void floyd() {
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> v >> e;
	init();

	while (e--) {
		int s, e, c;
		cin >> s >> e >> c;
		dist[s][e] = c;
	}
    
	floyd();

	int mn = INT_MAX;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			if (dist[i][j] == INT_MAX || dist[j][i] == INT_MAX) continue;
			mn = min(mn, dist[i][j] + dist[j][i]);
		}
	}

	cout << (mn == INT_MAX ? -1 : mn);
		
	return 0;
}