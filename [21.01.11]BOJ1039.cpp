/*
	21.01.11
	BOJ : 1039 교환 (https://www.acmicpc.net/problem/1039)
	BFS
*/
#include <bits/stdc++.h>
using namespace std;

int visited[11][1000005];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string N;
	int K;
	cin >> N >> K;

	int len = N.size();
	int ans = -1;

	queue <pair<string, int>> Q;
	Q.push({ N,0 });
	
	while (true) {
		int loop = Q.size();
		memset(visited, 0, sizeof(visited));

		if (!loop) break;

		while (loop--) {
			auto cur = Q.front(); Q.pop();

			if (cur.second == K) {
				ans = max(ans, stoi(cur.first));
				continue;
			}

			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					//스왑하고 큐에 넣기.
					string temp = cur.first;

					swap(temp[i], temp[j]);
					if (temp[0] == '0') continue;
					if (temp.size() == 2 && temp[1] == '0') continue;
					if (visited[cur.second + 1][stoi(temp)]) continue;
					visited[cur.second + 1][stoi(temp)] = 1;
					Q.push({ temp,cur.second + 1 });
				}
			}
		}
	}

	cout << ans;

	return 0;
}