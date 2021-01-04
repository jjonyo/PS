/*
	21.01.04
	BOJ : 1806 부분합 (https://www.acmicpc.net/problem/1806)
	구현
*/
#include <bits/stdc++.h>
using namespace std;

int arr[100001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	int N, S;
	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int ans = INT_MAX;
	int s, e, sum;
	s = e = sum = 0;
	
	while (true) {
		if (e == N && sum < S) break;
		else if (sum < S) {
			sum += arr[e++];
		}
		else if (sum >= S) {
			ans = min(ans, e - s);
			sum -= arr[s++];
		}
	}

	if (ans == INT_MAX) cout << 0;
	else cout << ans;
}