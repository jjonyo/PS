/*
	21.01.16
	BOJ : 2357 최솟값과 최대값 (https://www.acmicpc.net/problem/2357)
	자료구조/세그먼트 트리
*/
#include <bits/stdc++.h>
using namespace std;


typedef struct Node {
	int maxValue;
	int minValue;
	int value;
}Node;

Node* tree;
int* nums;
int N, M;
int S;

void init() {
	for (int i = S; i < 2 * S; i++) {
		if (i - S + 1 <= N) {
			tree[i].value = tree[i].maxValue = tree[i].minValue = nums[i - S + 1];
		}
		else {
			tree[i].value = 0;
			tree[i].maxValue = 0;
			tree[i].minValue = INT_MAX;
		}
	}

	for (int i = S - 1; i >= 1; i--) {
		tree[i].maxValue = max(tree[i * 2].maxValue, tree[i * 2 + 1].maxValue);
		tree[i].minValue = min(tree[i * 2].minValue, tree[i * 2 + 1].minValue);
	}
}

pair<int,int> query(int node, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return { INT_MAX,0 };
	else if (ql <= l && qr >= r) return { tree[node].minValue,tree[node].maxValue };
	else {
		int mid = (l + r) / 2;
		auto lValue = query(node * 2, l, mid, ql, qr);
		auto rValue = query(node * 2 + 1, mid + 1, r, ql, qr);
		
		return { min(lValue.first,rValue.first),max(lValue.second,rValue.second) };
	}

}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> M;

	nums = new int[N + 1];

	S = ceil(log2(N));
	S = (1 << S);

	tree = new Node[2 * S];

	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
	}

	init();

	for (int i = 0; i < M; i++) {
		int l, r;
		cin >> l >> r;
		auto ans = query(1, 1, S, l, r);
		cout << ans.first << " " << ans.second << '\n';
	}
	return 0;
}