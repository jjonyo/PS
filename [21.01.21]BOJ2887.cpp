/*
	21.01.21
	BOJ : 2887 행성 터널 (https://www.acmicpc.net/problem/2887)
	크루스칼 알고리즘
*/
#include <bits/stdc++.h>

using namespace std;

struct info {
	int a, b, c;
};

struct xyz {
	int x, y, z;
	int idx;
};
int n, m;
vector<info> adj;
xyz planet[100001];
int parent[1001];

bool cmp(info& a, info& b) {
	return a.c < b.c;
}

bool cmp2(xyz& a, xyz& b) {
	return a.x < b.x;
}

bool cmp3(xyz& a, xyz& b) {
	return a.y < b.y;
}

bool cmp4(xyz& a, xyz& b) {
	return a.z < b.z;
}


void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

}

int find(int a) {
	if (parent[a] == a) return a;

	parent[a] = find(parent[a]);
	return parent[a];
}

void unionf(int a, int b) {
	a = find(a);
	b = find(b);

	parent[a] = b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		planet[i] = { x,y,z,i };
	}
	sort(planet, planet + n, cmp2);

	for (int i = 0; i < n-1; i++) {
		adj.push_back({ planet[i].idx,planet[i + 1].idx,min({ abs(planet[i].x - planet[i+1].x),abs(planet[i].y - planet[i+1].y),abs(planet[i].z - planet[i+1].z) }) });
	}

	sort(planet, planet + n, cmp3);
	for (int i = 0; i < n - 1; i++) {
		adj.push_back({ planet[i].idx,planet[i + 1].idx,min({ abs(planet[i].x - planet[i + 1].x),abs(planet[i].y - planet[i + 1].y),abs(planet[i].z - planet[i + 1].z) }) });
	}

	sort(planet, planet + n, cmp4);
	for (int i = 0; i < n - 1; i++) {
		adj.push_back({ planet[i].idx,planet[i + 1].idx,min({ abs(planet[i].x - planet[i + 1].x),abs(planet[i].y - planet[i + 1].y),abs(planet[i].z - planet[i + 1].z) }) });
	}

	init();
	sort(adj.begin(), adj.end(), cmp);

	long long int ans = 0;
	for (int i = 0; i < adj.size(); i++) {
		auto cur = adj[i];

		if (find(cur.a) != find(cur.b)) {
			ans += cur.c;
			unionf(cur.a, cur.b);
		}
	}

	cout << ans;

	return 0;
}