/*
	21.01.12
	BOJ : 7453 합이 0인 네 정수 (https://www.acmicpc.net/problem/7453)
	이분탐색
*/
#include <bits/stdc++.h>
using namespace std;

int A[4001];
int B[4001];
int C[4001];
int D[4001];

vector <int> mergeA, mergeB;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	//두 개의 배열을 하나의 배열로 만들자.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = A[i] + B[j];
			mergeA.push_back(sum);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int sum = C[i] + D[j];
			mergeB.push_back(sum);
		}
	}

	//정렬
	//sort(mergeA.begin(), mergeA.end()); //A는 정렬 안해도 상관없음. (다 탐색하므로)
	sort(mergeB.begin(), mergeB.end());

	int i = 0, j = mergeB.size() - 1;

	int len = N * N;
	int sum = 0;
	long long int cnt = 0;
	long long int ans = 0;
	while (i < len) {
		int num = mergeA[i++];

		long long int lo = lower_bound(mergeB.begin(), mergeB.end(), -num) - mergeB.begin();
		long long int hi = upper_bound(mergeB.begin(), mergeB.end(), -num) - mergeB.begin();

		if (-num == mergeB[lo])
			ans += (hi - lo);
	}

	cout << ans;

	
	return 0;
}