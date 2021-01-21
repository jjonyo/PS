/*
	21.01.20
	BOJ : 앱 (https://www.acmicpc.net/problem/7579)
	다이나믹 프로그래밍
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int cost;
	int memory;
};
int dp[101][10001];
info app[101];

bool cmp(info& a, info& b) {
	return a.cost < b.cost;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> app[i].memory;
	}

	for (int i = 1; i <= n; i++) {
		cin >> app[i].cost;
	}

	for (int i = 1; i <= n; i++) { //i번 앱까지 고려했을 때
		for (int j = 0; j <= 10000; j++) { //cost j를 확보할 수 있는 최대 메모리
			dp[i][j]=dp[i - 1][j]; //i번째 앱을 사용하지 않았을 때
			if (j - app[i].cost >= 0) { 
				dp[i][j] = max(dp[i][j],dp[i - 1][j - app[i].cost] + app[i].memory); //i번째 앱을 사용 했을 때
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= 10000; i++) {
		if (dp[n][i] >= m) {
			ans = i;
			break;
		}
	}

	cout << ans;
	
	return 0;
}