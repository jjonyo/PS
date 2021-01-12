/*
	21.01.12
	BOJ : 두 배열의 합 (https://www.acmicpc.net/problem/2143)
	투포인터
*/
#include <bits/stdc++.h>
using namespace std;

int A[1001];
int B[1001];
vector <long long int> subA;
vector <long long int> subB;
map <int, int> countingA;
map <int, int> countingB;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T, N,M;
	cin >> T;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			subA.push_back(sum);
			countingA[sum]++;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			subB.push_back(sum);
			countingB[sum]++;
		}
	}

	sort(subA.begin(), subA.end());
	sort(subB.begin(), subB.end());
	
	int p1 = 0;
	int p2 = subB.size() - 1;
	long long int cnt = 0;
	
	while (true) {
	int sum = subA[p1] + subB[p2];
		if (sum > T) {
			p2--;
		}
		else if (sum < T) {
			p1++;
		}
		else { // sum == T
			//A에서 갯수세기.
			long long int curNumA = subA[p1];
			long long int curNumB = subB[p2];
	
			long Acount = countingA[curNumA];
			long Bcount = countingB[curNumB];

			cnt = cnt + (Acount * Bcount);

			p1 += Acount;
			p2 -= Bcount;
		}
	
		if (p2 < 0 || p1 >= subA.size()) break;
	}
	
	cout << cnt;
	
	return 0;
}