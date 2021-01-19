/*
	21.01.19
	BOJ : 11438 LCA2 (https://www.acmicpc.net/problem/11438)
	최소공통조상
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
int depth[100001], an[100001][18];
vector <int> adj[100001];
bool vis[100001];

void dfs(int parent, int cur, int paramDepth) {
	if (vis[cur]) return;
	vis[cur] = true;
	depth[cur] = paramDepth;
	an[cur][0] = parent;
	for (int i = 0; i < adj[cur].size(); i++) {
		dfs(cur, adj[cur][i], paramDepth + 1);
	}
}

int LCA(int a, int b) {
	//깊이가 서로 다르면 맞춰준다.

	if (depth[a] < depth[b]) { //a의 깊이가 b보다 더 깊게 만들어서 쉽게 처리하기 위함.
		int tmp = a;
		a = b;
		b = tmp;
	}

	if (depth[a] != depth[b]) {
		// a의깊이가 b의 깊이와 같아질 때 까지 맞춘다.
		int diff = depth[a] - depth[b];
		for (int i = 0; i <= 17; i++) {
			if (diff & (1 << i)) {
				a = an[a][i];
			}
		}
	}

	//depth[a] == depth[b] && a == b면 그게 공통조상임.
	if (a == b) return a;

	for (int i = 17; i >= 0; i--) {
		if (an[a][i] != an[b][i]) {
			a = an[a][i];
			b = an[b][i];
		}
	}

	//LCA의 바로 아래까지옴.
	return an[a][0];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		//일단 양방향으로 연결
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//LCA를 위한 자료 수집 : 각 노드에 대한 깊이
	dfs(1, 1, 1);

	//2^1, 2^2, 2^3 ... 조상 set
	for (int i = 1; i <= 17; i++) { // 2^i번째 조상.
		for (int j = 1; j <= N; j++) { //1번 노드부터 N번 노드 까지
			int tmp = an[j][i - 1];
			an[j][i] = an[tmp][i - 1];
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}