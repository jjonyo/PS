/*
	21.01.19
	BOJ : 1916 최소비용 구하기 (https://www.acmicpc.net/problem/1916)
	다익스트라 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int num;
	int dist;

	info(int n, int d) {
		num = n;
		dist = d;
	}
};

struct comp {
	bool operator()(info& a, info& b) {
		return a.dist > b.dist;
	}
};

int v, e;
vector<pair<int,int>> adj[20001];
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int dist[20001];



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
	}

	for (int i = 1; i <= v; i++) {
		dist[i] = INT_MAX;
	}

	int start, target;
	cin >> start >> target;

	dist[start] = 0;
	pq.push({0,start});

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		if (dist[cur.second] < cur.first) continue;

		for (int i = 0; i < adj[cur.second].size(); i++) {
			int nxt = adj[cur.second][i].first;
			int nDist = adj[cur.second][i].second;
			if (cur.first + nDist < dist[nxt]) {
				dist[nxt] = cur.first + nDist;
				pq.push({ dist[nxt],nxt });
			}
		}

	}

	cout << dist[target];
	return 0;
}