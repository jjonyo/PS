/*
	21.01.04
	BOJ : 1644 부분합 (https://www.acmicpc.net/problem/1644)
	투 포인터
*/
#include <bits/stdc++.h>
using namespace std;

bool check[4000001];

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	vector <int> arr;
	int n;
	cin >> n;

	if (n == 1) {
		cout << 0;
		return 0;
	}

	if (n == 2) {
		cout << 1;
		return 0;
	}

	int rootSqrt = sqrt(n);
	
	for (int i = 2; i <= rootSqrt; i++) {
		if (check[i]) {
			continue;
		}
		for (int j = i + i; j <= n; j += i) {
			check[j] = true;
		}
	}
	
	for (int i = 2; i <= n; i++) {
		if (!check[i])
			arr.push_back(i);
	}

	int s, e, sum, ans;
	s = e = sum = ans=0;
	int size = arr.size();
	while (e<size) {
		if (sum < n) {
			sum += arr[e++];
		}
		else {
			sum -= arr[s++];
		}

		if (sum == n) ans++;
	}
	
	if (!check[n]) ans++;

	cout << ans;
}