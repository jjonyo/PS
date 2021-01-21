/*
	21.01.20
	BOJ : 5582 공통 부분 문자열 (https://www.acmicpc.net/problem/5582)
	다이나믹 프로그래밍
*/
#include <bits/stdc++.h>
using namespace std;

string str1, str2;
int len1, len2;
int dp[4010][4010];

int calc(int p1, int p2) {
	if (p1 < 0 || p2 < 0)return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];
	if (str1[p1] == str2[p2]) {
		return dp[p1][p2] = calc(p1 - 1, p2 - 1) + 1;
	}

	return 0;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	cin >> str1 >> str2;

	len1 = str1.size();
	len2 = str2.size();

	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			dp[i][j] = -1;
		}
	}

	int ans = 0;
	for (int i = 0; i <= len1 - 1; i++) {
		for (int j = 0; j <= len2 - 1; j++) {
			ans = max(ans, calc(i, j));
		}
	}

	cout << ans;
	return 0;
}