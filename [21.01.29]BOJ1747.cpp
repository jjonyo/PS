/*
	21.01.29
	BOJ : 1747 촌수계산 (https://www.acmicpc.net/problem/1747)
	소수판별
*/
#include <bits/stdc++.h>
using namespace std;

bool check[1003002];
vector <int> prime;

bool isP(string s) {
	int len = s.size();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - 1 - i]) {
			return false;
		}
	}

	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	for (int i = 2; i <= 1003001; i++) {
		if (check[i]) continue;

		for (int j = 2 * i; j <= 1003001; j += i) {
			check[j] = 1;
		}
	}

	for (int i = 2; i <= 1003001; i++) {
		if (!check[i])
			prime.push_back(i);
	}

	int n;
	cin >> n;
	
	auto s = lower_bound(prime.begin(), prime.end(),n);
	
	for (; s != prime.end(); s++) {
		if (isP(to_string(*s))) {
			cout << *s;
			break;
		}
	}
	
	return 0;
}