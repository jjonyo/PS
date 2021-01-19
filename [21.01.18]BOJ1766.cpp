/*
	21.01.18
	BOJ : 1766 문제집 (https://www.acmicpc.net/problem/1766)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;


int N, M;
int indegree[32001];
vector <int> adj[32001];
priority_queue<int,vector<int>,greater<int>> Q;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		adj[a].push_back(b);
		indegree[b]++;
	}

	//indegree가 0인것을 찾음.(사이클 없으므로 가능)
	//어딘가 모아놓음, 모아놓은 것을 하나씩 뽑으면서 출력하고 연결된것들의 간선 제거
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			Q.push(i);
		}
		
	}

	while (!Q.empty()) {
		int cur = Q.top();
		Q.pop();
		printf("%d ", cur);
		for (int i = 0; i < adj[cur].size(); i++) {
			int nxt = adj[cur][i];
			indegree[nxt]--;
			if (indegree[nxt] == 0) {
				Q.push(nxt);
			}
		}
	}

	return 0;
}