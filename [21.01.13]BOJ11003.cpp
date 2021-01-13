/*
	21.01.13
	BOJ 11003 : 최솟값 찾기 (https://www.acmicpc.net/problem/11003)
	자료구조 / 덱
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, L;
	cin >> N >> L;

	deque <pair<int, int>> deq;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		if (!deq.empty() && deq.front().second <= i - L) {
			deq.pop_front();
		}

		while (!deq.empty() && deq.back().first > n) {
			deq.pop_back();
		}

		deq.push_back({n,i});
		cout << deq.front().first << " ";
	}



	return 0;
}