/*
	21.01.24
	BOJ : 16562 친구비  (https://www.acmicpc.net/problem/16562)
	유니온 파인드
*/
#include <bits/stdc++.h>
using namespace std;

int p[10001];
int cost[10001];
bool vis[10001];
int n, m, k;


void init() {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
}

int find(int a) {
	if (p[a] == a) return a;
	p[a] = find(p[a]);
	return p[a];
}

void unionf(int a, int b) {
	a = find(a);
	b = find(b);
	cost[b] = min(cost[a], cost[b]);
	p[a] = b;
}

int calc() {

	int totalCost = 0;
	for (int i = 1; i <= n; i++) {
		int n = find(i);
		if (vis[n]) continue;
		totalCost += cost[n];
		vis[n] = 1;
	}

	return totalCost;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	init();
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		unionf(a, b);
	}
	
	int result = calc();

	if (k >= result) cout << result;
	else cout << "Oh no";
	return 0;
}