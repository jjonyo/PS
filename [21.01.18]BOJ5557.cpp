/*
	21.01.18
	BOJ : 5557 1학년 (https://www.acmicpc.net/problem/5557)
	동적계획법
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int N;
ll dp[101][2001];
int arr[101];

ll dfs(int n, int s) {
	if (s < 0 || s > 20) return 0;
	if (n == N - 1) {
		if (s == arr[N]) {
			return 1;
		}
		else return 0;
	}

	if (dp[n][s] != -1) return dp[n][s];

	dp[n][s] = 0;
	dp[n][s] += dfs(n + 1, s + arr[n + 1]);
	dp[n][s] += dfs(n + 1, s - arr[n + 1]);
	
	return dp[n][s];
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	memset(dp, -1, sizeof(dp));

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout<<dfs(1, arr[1]);
	return 0;
}