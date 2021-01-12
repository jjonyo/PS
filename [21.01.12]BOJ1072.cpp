/*
	21.01.12
	BOJ 1072 : 게임 (https://www.acmicpc.net/problem/1072)
	이분탐색
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long X, Y, Z;

	cin >> X >> Y;

	Z = 100 * Y / X;
	if (Z >= 99) {
		cout << -1;
		return 0;
	}
	int st = 0, ed = 1000000000;
	int target = Z + 1;
	int mid = 0;
	int ans = 0;
	while (st < ed) {
		mid = (st + ed) / 2;
		
		int rate = (100 * (Y + mid) / (X + mid));
		if (rate <= Z) {
			st = mid + 1;
		}
		else {
			ed = mid;
		}

	}

	if (ed > 1000000000) {
		cout << -1;
	}
	else {
		cout << ed;
	}

	
	return 0;
}