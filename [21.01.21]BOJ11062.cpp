/*
	21.01.21
	BOJ : 11062 카드 게임 (https://www.acmicpc.net/problem/11062)
	다이나믹 프로그래밍
*/
#include <bits/stdc++.h>
using namespace std;

int g_dp[1001][1001];
int m_dp[1001][1001];
int card[1001];
int subsum[1001];
int tc;
int n;

int g_play(int s, int e);
int m_play(int s, int e);

int getsum(int s, int e) {
	return subsum[e] - subsum[s - 1];
}

int g_play(int s, int e) {
	if (s == e) return card[s];
	if (g_dp[s][e] != -1) return g_dp[s][e];
	int left = card[s] + (getsum(s+1,e) - m_play(s + 1, e));
	int right = card[e] + (getsum(s,e-1) - m_play(s, e-1));

	return g_dp[s][e] = max(left, right);
}

int m_play(int s, int e) {
	if (s == e) return card[s];
	if (m_dp[s][e] != -1) return m_dp[s][e];
	int left = card[s] + (getsum(s+1,e) - g_play(s + 1, e));
	int right = card[e] + (getsum(s,e-1) - g_play(s, e - 1));

	return m_dp[s][e] = max(left, right);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> tc;
	while (tc--) {
		memset(g_dp, 0xff, sizeof(g_dp));
		memset(m_dp, 0xff, sizeof(m_dp));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> card[i];
			subsum[i] = subsum[i - 1] + card[i];
		}

		cout << g_play(1, n)<<'\n';
	}

	return 0;
}