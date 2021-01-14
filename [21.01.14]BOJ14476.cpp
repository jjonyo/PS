/*
	21.01.14
	BOJ : 14476 최대공약수 하나 빼기 (https://www.acmicpc.net/problem/14476)
	정수론/유클리드 호제법
*/
#include <bits/stdc++.h>
using namespace std;

int leftGcd[1000002];
int rightGcd[1000002];
int arr[1000002];

// gcd(a,b) = gcd(b,a%b)
int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;


	for (int i = 1; i <= N;i++) {
		cin >> arr[i];
	}

	leftGcd[1] = arr[1];
	rightGcd[N] = arr[N];

	for (int i = 2; i <= N; i++) {
		leftGcd[i] = gcd(leftGcd[i-1],arr[i]);
	}

	for (int i = N-1; i >= 1; i--) {
		rightGcd[i] = gcd(rightGcd[i + 1], arr[i]);
	}

	int ans = 0;
	int ansGcd = 0;
	for (int i = 1; i <= N; i++) {
		int Gcd = gcd(leftGcd[i - 1], rightGcd[i + 1]);

		if (arr[i] % Gcd != 0 && Gcd>ansGcd) {
			ans = arr[i];
			ansGcd = Gcd;
		}
	}

	if (ans == 0 && ansGcd == 0) {
		cout << -1;
	}
	else {
		cout << ansGcd << " " << ans;
	}
	
	return 0;
}