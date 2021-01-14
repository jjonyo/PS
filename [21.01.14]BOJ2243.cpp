/*
	21.01.14
	BOJ : 2243 청소년 상어 (https://www.acmicpc.net/problem/2243)
	자료구조/세그먼트 트리
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll* nums;
ll* tree;
int N, Q, S;

#define MAX 1000000

void init() {
	for (int i = 1; i < 2 * S; i++) {
		tree[i] = 0;
	}
}

ll query(int node, int start, int end, int candy) {	
	if (candy > tree[node] || candy < 1) return 0;

	tree[node] -= 1;
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	int d = tree[node * 2];
	return query(node * 2, start, mid, candy) + query(node * 2 + 1, mid + 1, end, candy - d);
}

void update(int node, int left, int right, int index, ll diff) {
	if (left <= index && index <= right) {
		tree[node] += diff;
		if (left != right) {
			int mid = (left + right) / 2;
			update(node * 2, left, mid, index, diff);
			update(node * 2 + 1, mid + 1, right, index, diff);
		}
	}
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	S = ceil(log2(MAX));
	S = (1 << S);

	tree = new ll[2 * S];

	init();

	cin >> N;
	for (int i = 0; i < N; i++) {
		int A, B, C;
		cin >> A;
		if (A == 1) {
			cin >> B;
			cout << query(1, 1, S, B) <<'\n';
		}
		else if (A == 2) {
			cin >> B >> C;
			update(1, 1, S, B, C);
		}
	}

	return 0;
}