/*
	21.01.25
	BOJ : 4792 레드 블루 스패닝 트리  (https://www.acmicpc.net/problem/4792)
	MST
*/
#include <bits/stdc++.h>
using namespace std;

struct edge {
	int a;
	int b;
	int c;
};
int	p[10001];
int n, m, k;
vector <edge> adj;

bool mincmp(edge& a, edge& b) {
	return a.c < b.c;
}

bool maxcmp(edge& a, edge& b) {
	return a.c > b.c;
}

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
	p[a] = b;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) break;

		for (int i = 0; i < m; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;

			if (c == 'R') {
				adj.push_back({ a,b,1 });
			}
			else if (c == 'B') {
				adj.push_back({ a,b,0 });
			}
		}

		//min값 구하기. (red우선)

		sort(adj.begin(), adj.end(), maxcmp);
		init();
		int minBlue = 0;
		for (int i = 0; i < adj.size(); i++) {
			auto cur = adj[i];

			if (find(cur.a) != find(cur.b)) {
				if (cur.c == 0) {
					minBlue++;
				}
				unionf(cur.a, cur.b);
			}
		}

		//max값 구하기. (blue우선)

		sort(adj.begin(), adj.end(), mincmp);
		init();
		int maxBlue = 0;
		for (int i = 0; i < adj.size(); i++) {
			auto cur = adj[i];

			if (find(cur.a) != find(cur.b)) {
				if (cur.c == 0) {
					maxBlue++;
				}
				unionf(cur.a, cur.b);
			}
		}

		if (k >= minBlue && k <= maxBlue) cout << 1 << '\n';
		else cout << 0 << '\n';
		
		adj.clear();
	}
	return 0;
}