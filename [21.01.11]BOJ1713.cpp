/*
	21.01.11
	BOJ : 1713 후보 추천하기 (https://www.acmicpc.net/problem/1713)
	구현/시뮬레이션
*/
#include <bits/stdc++.h>
using namespace std;

int N, C;
int idx[101] = { 0 };
vector <pair<int,int>> tle;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> C;

	fill(idx, idx + 101, -1);

	for (int i = 0; i < C; i++) {
		int n;
		cin >> n;

		if (idx[n] == -1) { //해당 학생이 사진틀에 없음.
			//사진틀의 크기 확인하고 넣기
			if (tle.size() >= N) { //꽉참
				int len = tle.size();
				int min_idx=-1;
				int min_val = INT_MAX;
				for (int j = 0; j < len; j++) {
					if (tle[j].second < min_val) {
						min_val = tle[j].second;
						min_idx = j;
					}
				}

				idx[tle[min_idx].first] = -1;
				tle.erase(tle.begin()+min_idx);

				for (int j = 0; j < len - 1; j++) {
					idx[tle[j].first] = j;
				}

				tle.push_back({ n,1 });
				idx[n] = tle.size() - 1;
			}
			else { //비어있음
				tle.push_back({n,1});
				idx[n] = tle.size() - 1;
			}
		}
		else { //사진틀에 이미 있음
			//인덱스로 접근해 추천수 증가시키기
			tle[idx[n]].second++;
		}
	}

	sort(tle.begin(), tle.end());

	for (auto c : tle) {
		cout << c.first << " ";
	}

	return 0;
}