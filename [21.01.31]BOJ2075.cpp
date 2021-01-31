/*
	21.01.31
	BOJ : 2075 N번째 큰 수 (https://www.acmicpc.net/problem/2075)
	우선순위 큐
*/
#include <bits/stdc++.h>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	int N;
	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int n;
		cin >> n;

		if (pq.size() < N) {
			pq.push(n);
		}
		else {
			if (pq.top() < n) {
				pq.pop();
				pq.push(n);
			}
		}
	}

	cout << pq.top();

	return 0;
}