/*
	21.01.06
	BOJ : 1715 카드 정리 (https://www.acmicpc.net/problem/1715)
	자료구조
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	priority_queue<int,vector<int>,greater<int>> Q;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		Q.push(val);
	}

	int ans = 0;
	while (Q.size() != 1) {
		int n1 = Q.top(); Q.pop();
		int n2 = Q.top(); Q.pop();
		ans += n1 + n2;
		Q.push(n1 + n2);
	}

	cout << ans;
}