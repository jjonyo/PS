/*
	21.01.27
	BOJ : 20056 마법사 상어와 파이어볼 (https://www.acmicpc.net/problem/20056)
	시뮬레이션
*/
#include <bits/stdc++.h>
using namespace std;

struct info {
	int r;
	int c;
	int m;
	int s;
	int d;
};

int N, M, K;
vector <info> board[51][51];
vector <info> fList;

int total = 0;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

int dir1[4] = { 0,2,4,6 };
int dir2[4] = { 1,3,5,7 };

int getRotation(int cur) {
	if (cur < 0) {
		int d = cur % N;
		if (d != 0) {
			d += N;
		}
		return d;
	}
	else if (cur >= N) {
		return cur % N;
	}
	else {
		return cur;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		board[r - 1][c - 1].push_back({ m,s,d });
		fList.push_back({ r - 1,c - 1,m,s,d });
		total += m;
	}
	
	while (K--) {
		int len = fList.size();
	
		//이동 처리
		vector <info> temp;
		for (int i = 0; i < len; i++) {
			auto cur = fList[i];
	
			int nr = cur.r + dx[cur.d] * cur.s;
			int nc = cur.c + dy[cur.d] * cur.s;
	
			nr = getRotation(nr);
			nc = getRotation(nc);
		
			temp.push_back({ nr,nc,cur.m,cur.s,cur.d });
			board[cur.r][cur.c].clear();
		}

		for (auto cur : temp) {
			board[cur.r][cur.c].push_back({ cur.r,cur.c,cur.m,cur.s,cur.d });
		}

		fList.clear();
		//파이어볼 합치고 나누기.
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j].empty()) continue;
				else {
					if (board[i][j].size() == 1) {
						auto cur = board[i][j].front();
						fList.push_back({ i,j,cur.m,cur.s,cur.d });
						board[i][j].clear();
						continue;
					}
				}

				int sum_m = 0;
				int sum_s = 0;
				bool odd = true;
				bool even = true;
				vector <int> idx;
				for (auto cur : board[i][j]) {
					sum_m += cur.m;
					sum_s += cur.s;
					if (cur.d % 2 == 0) {
						odd = false;
					}
					else {
						even = false;
					}
				}

				int newm = sum_m / 5;
				int news = sum_s / (int)board[i][j].size();

				total -= sum_m;
				total += (newm * 4);

				int* newd;
				if (even || odd) { //모두 홀수거나 짝수
					newd = dir1;
				}
				else {
					newd = dir2;
				}

				if (newm == 0) { //질량이 0일경우 소멸
					board[i][j].clear();
					continue;
				}

				for (int dir = 0; dir < 4; dir++) {
					fList.push_back({ i,j,newm,news,newd[dir] });
				}

				board[i][j].clear();
			}
		}
	}

	cout << total;

	return 0;
}