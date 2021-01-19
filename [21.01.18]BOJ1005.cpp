/*
	21.01.18
	BOJ : 1005 ACM Craft (https://www.acmicpc.net/problem/1005)
	위상정렬
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> adj[1001];
int buildTime[1001];
int indegree[1001];
int dp[1001];
int ans[1001];

queue<int> q;
int T, N, K;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		for (int i = 0; i <= N; i++) {
			adj[i].clear();
		}
		while (!q.empty()) { q.pop(); }
		memset(buildTime, 0, sizeof(buildTime));
		memset(indegree, 0, sizeof(indegree));
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));


		cin >> N >> K;
		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			buildTime[i] = temp;
		}

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;

			adj[x].push_back(y);
			indegree[y]++;
		}

		int target;
		cin >> target;

		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			int cur = q.front(); q.pop();		
			ans[cur] = dp[cur] + buildTime[cur];
			if (cur == target) {
				cout << ans[cur] << '\n';
				break;
			}
			for (int i = 0; i < adj[cur].size(); i++) {
				int nxt = adj[cur][i];
				dp[nxt] = max(dp[nxt], ans[cur]);
				indegree[nxt]--;
				if (indegree[nxt] == 0) q.push(nxt);
			}
		}
	}
	
	return 0;
}