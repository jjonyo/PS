/*
	21.01.22
	BOJ : 2098 외판원 순회 (https://www.acmicpc.net/problem/2098)
	동적계획법, 비트마스킹
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[16][1 << 16];
int w[17][17];

int setMask(int cur,int n) {
	cur = cur ^ (1 << n);
	return cur;
}

bool isTravle(int visit,int cur) {
	return visit & 1 << cur;
}

long long int travel(int cur, int visit) {
	//방문할 수 있는곳에 대해서 방문한 값중 최소값 저장.
	//기저조건 -> 모든 곳을 방문하고 이곳에 도착했을때. visit == (1<<n)-1 일 때
	//다음 방문할곳을 방문체크하고, 방문
	//방문은 현재 있는곳에서 갈 수 있는곳 모두(방문한 적 없고, 거리가 0 이상이여야 갈 수 있음)

	visit = setMask(visit, cur);
	if (dp[cur][visit] != -1) {
		return dp[cur][visit];
	}

	if (visit + 1 == (1 << n)) { //모든 곳 방문
		if (w[cur][0] == 0) return INT_MAX; //실수한 부분. 마지막 방문 지점에서 시작점으로 돌아갈 수 있는지 확인.
		else return w[cur][0];
	}

	long long int minValue = INT_MAX; //long long int안하면 오버플러우난다. 방문할 수 있는곳이 없는경우 int_max 반환하므로..
	for (int i = 0; i < n; i++) {
		if (w[cur][i] == 0) continue;
		if (isTravle(visit, i) == 1) continue;
		minValue = min(minValue, travel(i, visit) + w[cur][i]);
	}
	
	return dp[cur][visit] = minValue;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	memset(dp, 0xff, sizeof(dp));

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}

	cout << travel(0, 0);

	return 0;
}