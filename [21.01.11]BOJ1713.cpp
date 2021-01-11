틀 만들기. 벡터로.

추천을 받으면
해당 번호가 틀에 있는지 확인.(틀에 있다면 틀의 인덱스번호를 번호별로 저장하고 있음)
틀에 없으면 인덱스를 기록하고 push_back한다.
틀에 있으면 그 인덱스로 접근해 값을 1 증가시킨다.

틀에 추가할때 벡터의 사이즈가 틀의 개수보다 크다면 삭제를 해야한다.
이때는 맨 끝에서부터 , 추천수가 다를때까지 이동한다음에 그 해당 인덱스를 지우고
새로운걸 푸쉬한다.

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