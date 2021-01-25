/*
	21.01.25
	BOJ : 18436 수열과 쿼리 37  (https://www.acmicpc.net/problem/18436)
	세그먼트 트리
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

class info {
public:
	int val;
	int odd;
	int even;

	info() :val(0),odd(0),even(0) {}
};

info tree[300000];
int n,m;
int s;
int nums[100001];

bool isOdd(int n) {
	return (n % 2);
}

void update(int index, int val) {
	int node = s + index - 1;
	int onum = nums[index];

	tree[node].val = val;
	nums[index] = val;

	if (isOdd(onum) == isOdd(val)) {
		return;
	}
	else {
		if (isOdd(onum)) { //홀수일 경우
			tree[node].odd--;
			tree[node].even++;
		}
		else {
			tree[node].even--;
			tree[node].odd++;
		}
	}

	int p = node / 2;
	while (p >= 1) {
		tree[p].even = tree[p * 2].even + tree[p * 2 + 1].even;
		tree[p].odd = tree[p * 2].odd + tree[p * 2 + 1].odd;

		p /= 2;
	}
}

void init() {
	for (int i = s; i < 2*s; i++) {
		if (i-s+1 <= n) {
			tree[i].val = nums[i-s+1];
			if (nums[i-s+1] % 2 == 0) {
				tree[i].even++;
			}
			else {
				tree[i].odd++;
			}
		}
		else {
			tree[i].val = 0;
		}
	}

	for (int i = s - 1; i >= 1; i--) {
		tree[i].even = tree[2 * i].even + tree[2 * i + 1].even;
		tree[i].odd = tree[2 * i].odd + tree[2 * i + 1].odd;
	}
}

pii query(int node, int left, int right, int qleft, int qright) {
	if (qleft > right || left > qright) return {0,0};
	else if (left >= qleft && right <= qright) { //완전 포함
		return { tree[node].odd,tree[node].even };
	}
	else {
		int mid = (left + right) / 2;
		pii lres = query(node * 2, left, mid, qleft, qright);
		pii rres = query(node * 2 + 1, mid + 1, right, qleft, qright);
		int even = lres.second + rres.second;
		int odd = lres.first + rres.first;
		return {odd,even};
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	s = ceil(log2(n));
	s = (1 << s);

	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
	}

	init();


	cin >> m;

	while (m--) {
		int q, l, r;
		cin >> q >> l >> r;
		if (q == 1) {
			update(l, r);
		}
		else if (q == 2) {
			cout << query(1, 1, s, l, r).second << '\n';
		}
		else if (q == 3) {
			cout << query(1, 1, s, l, r).first << '\n';
		}
	}


	return 0;
}