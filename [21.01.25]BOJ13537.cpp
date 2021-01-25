/*
	21.01.25
	BOJ : 13537 수열과 쿼리 1  (https://www.acmicpc.net/problem/13537)
	세그먼트 트리
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> tree[300000];
int n,m;
int s;

void init(int node, int index, int val, int left, int right) {
	if (index >= left && index <= right) {
		tree[node].push_back(val);

		if (left != right) {
			int mid = (left + right) / 2;
			init(node * 2, index, val, left, mid);
			init(node * 2 + 1, index, val, mid + 1, right);
		}
	}
}

int query(int node, int left, int right, int qleft, int qright, int val) {
	if (qleft > right || left > qright) return 0;
	else if (left >= qleft && right <= qright) { //완전 포함
		int cnt = tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
		return cnt;
	}
	else {
		int mid = (left + right) / 2;
		int cnt = query(node * 2, left, mid, qleft, qright, val) + query(node * 2 + 1, mid + 1, right, qleft, qright, val);
		return cnt;
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	s = ceil(log2(n));
	s = (1 << s);

	for (int i = 1; i <= s; i++) {
		if (i <= n) {
			int val;
			cin >> val;
			init(1, i, val, 1, s);
		}
		else {
			init(1, i, INT_MAX, 1, s);
		}
	}

	for (int i = 1; i < 2 * s; i++) {
		sort(tree[i].begin(), tree[i].end());
	}

	cin >> m;

	while (m--) {
		int l, r, v;
		cin >> l >> r >> v;

		cout << query(1, 1, s, l, r, v) <<'\n';
	}


	return 0;
}