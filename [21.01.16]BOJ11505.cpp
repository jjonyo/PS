/*
	21.01.16
	BOJ : 11505 구간 곱 구하기 (https://www.acmicpc.net/problem/11505)
	자료구조/세그먼트 트리
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MAX 1000000007
ll* tree;
ll* nums;
int S;
int N, M,K;

void init() {
	for (int i = S; i < 2 * S; i++) {
		if (i - S + 1 <= N) {
			tree[i] = nums[i-S+1];
		}
		else {
			tree[i] = 1;
		}
	}

	for (int i = S - 1; i >= 1; i--) {
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MAX;
	}
}

ll query(int node, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return 1;
	else if (l >= ql && r <= qr) return tree[node];
	else {
		int mid = (l + r) / 2;
		return (query(node * 2, l, mid, ql, qr) * query(node * 2 + 1, mid + 1, r, ql, qr)) % MAX;
	}
}


void update(int node,int newValue) {
	nums[node] = newValue;
	node = S + node - 1;
	tree[node] = newValue;
	while (node >= 1) {
		node /= 2;
		tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MAX;
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	cin >> N >> M >> K;

	nums = new ll[N + 1];

	for (int i = 1; i <= N; i++)
	{
		cin >> nums[i];
	}

	S = ceil(log2(N));
	S = (1 << S);

	tree = new ll[2 * S] ;

	init();

	for (int i = 0; i < M + K; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b, c);
		}
		else if (a == 2) {
			cout << query(1, 1, S, b, c)<<'\n';
		}
	}

	return 0;
}