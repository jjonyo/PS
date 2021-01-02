/*
	21.01.02
	BOJ : 20055 컨베이어 벨트 위의 로봇 (https://www.acmicpc.net/problem/20055)
	구현
*/
#include <bits/stdc++.h>
using namespace std;

int N, K;
list <pair<int,int>> belt;
list <pair<int, int>>::iterator up;
list <pair<int, int>>::iterator down;
void rotation() {
	up--;
	down--;
	belt.push_front(belt.back());
	belt.pop_back();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		belt.push_back({temp,0});
	}
	down = belt.end();
	down--;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		belt.push_back({ temp,0 });
	}

	up = belt.end();
	up--;

	int cnt = 0;
	int zeroCount = 0;
	while (true) {
		rotation();
		auto iter = up;
		auto prev = belt.begin();
		if (down->second == 1) {
			down->second = 0;
		}
		while (iter != belt.begin()) {
			if (prev->first > 0 && prev->second == 0 &&iter ->second == 1) { //다음 칸으로 이동할 수 있는 경우
				iter->second = 0;
				prev->first -= 1;
				prev->second = 1;
				if (prev->first == 0) {
					zeroCount++;
				}
			}
			prev = iter;
			iter--;
		}
		if (belt.begin()->first>0 && belt.begin()->second==0) {
			belt.begin()->first -= 1;
			belt.begin()->second = 1;
			if (belt.begin()->first == 0)
				zeroCount++;
		}

		if (down->second == 1) {
			down->second = 0;
		}
		cnt++;
		if (zeroCount >= K) {
			cout << cnt;
			return 0;
		}
	}
}

