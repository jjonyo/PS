/*
	21.01.11
	BOJ : 1062 가르침 (https://www.acmicpc.net/problem/1062)
	백트래킹
*/
#include <bits/stdc++.h>
using namespace std;


int idx[26] = { 0 };

int N, K;
int selectedCount = 0;
int ans = 0;
vector <string> word;

void dfs(int index) {
	if (selectedCount == K) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			string cur = word[i];

			int len = cur.size();
			bool check = true;
			for (int j = 0; j < len; j++) {
				if (idx[cur[j] - 'a'] == 0) {
					check = false;
					break;
				}
			}

			if (check)
				cnt++;
		}

		ans = max(ans, cnt);
		return;
	}

	for (int i = index; i < 26; i++) {
		if (idx[i]) continue;
		idx[i] = 1;
		selectedCount += 1;
		dfs(i);
		idx[i] = 0;
		selectedCount -= 1;
	}
	
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		word.push_back(temp);
	}

	if (K < 5) {
		cout << 0;
		return 0;
	}

	

	idx['a' - 'a'] = 1;
	idx['c' - 'a'] = 1;
	idx['i' - 'a'] = 1;
	idx['n' - 'a'] = 1;
	idx['t' - 'a'] = 1;
	

	for (int i = 0; i < 26; i++) {
		if (idx[i]) continue;
		selectedCount = 5;
		dfs(i);
	}
	cout << ans;
	return 0;
}