/*
	21.01.09
	BOJ : 14921 스타트 택시 (https://www.acmicpc.net/problem/14921)
	두 포인터
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;

	vector<int> arr;

	while (N--) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	int st = 0;
	int ed = arr.size() -1;
	int ans = INT_MAX;
	bool sign = 0;
	while (st < ed) {
		int num = arr[st] + arr[ed];
		if (num < 0) {
			st++;
		}
		else if (num>0){
			ed--;
		}
		else {
			cout << 0;
			return 0;
		}

		if (abs(num) < ans) {
			ans = abs(num);
			sign = num > 0 ? 1 : 0;
		}

	}
	
	if (sign) {
		cout << ans;
	}
	else {
		cout << ans*-1;
	}
	return 0;
}