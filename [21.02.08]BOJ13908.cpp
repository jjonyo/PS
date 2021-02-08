/*
	21.02.08
	BOJ : 13908 비밀번호 (https://www.acmicpc.net/problem/13908)
	백트래킹/브루트포스
*/
#include <bits/stdc++.h>

using namespace std;

int n, m;
int num[7];
int check[10];
int ans = 0;

void dfs(int cur) {
	if (cur == n) {
		//검사
		for (int i = 0; i < m; i++) {
			if (check[num[i]] == 0)
				return;
		}
		ans++;
		return;
	}

	for (int i = 0; i <= 9; i++) {
		check[i]++;
		dfs(cur + 1);
		check[i]--;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}

	dfs(0);

	cout << ans;
	
	return 0;
}