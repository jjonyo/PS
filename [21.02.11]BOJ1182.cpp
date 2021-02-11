/*
	21.02.11
	BOJ : 1182 부분수열의 합 (https://www.acmicpc.net/problem/1182)
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define val first
#define num second

int n, s;
int arr[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += arr[j];
				//cout << arr[j]<<" ";
			}
		}
		if (sum == s) {
			ans++;
		}
	}

	cout << ans;
	return 0;
}