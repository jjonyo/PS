/*
	21.01.18
	BOJ : 1922 네트워크 연결 (https://www.acmicpc.net/problem/1922)
	크루스칼 알고리즘
*/
#include <bits/stdc++.h>
using namespace std;

struct info { //간선의 크기순으로 정렬하기 위하여 구조체 사용
	int a, b, c;
};

int N, M;
info edge[100001]; //간선의 정보들
int p[100000000]; //유니온 파인드에 이용

void init() {
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
}

int findf(int a) {
	if (a == p[a]) return a;

	p[a] = findf(p[a]);
	return p[a];
}

void unionf(int a, int b) {
	a = findf(a);
	b = findf(b);
	p[a] = b;
}

bool cmp(info& a, info& b) {
	return a.c < b.c;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[i] = { a,b,c };
	}

	//간선의 크기 순으로 정렬
	sort(edge, edge + M, cmp);
	//union-find 이용해 트리 구성
	init();
	int ans = 0;
	for (int i = 0; i < M; i++) {
		int a = edge[i].a;
		int b = edge[i].b;

		if (findf(a) != findf(b)) {
			unionf(a, b);
			ans += edge[i].c;
		}
	}

	cout << ans;
	return 0;
}