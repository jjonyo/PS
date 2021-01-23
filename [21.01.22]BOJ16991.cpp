/*
	21.01.22
	BOJ : 16991 외판원 순회3  (https://www.acmicpc.net/problem/16991)
	동적계획법, 비트마스킹
*/
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n;
double dp[16][1 << 16];
pair <int, int> w[17];

int setMask(int cur,int n) {
	cur = cur ^ (1 << n);
	return cur;
}

bool isTravle(int visit,int cur) {
	return visit & 1 << cur;
}

double getDist(int from, int to) {
	int x = w[to].X - w[from].X;
	int y = w[to].Y - w[from].Y;

	double ret = sqrt(pow(x, 2) + pow(y, 2));

	return ret;
}

double travel(int cur, int visit) {
	//방문할 수 있는곳에 대해서 방문한 값중 최소값 저장.
	//기저조건 -> 모든 곳을 방문하고 이곳에 도착했을때. visit == (1<<n)-1 일 때
	//다음 방문할곳을 방문체크하고, 방문
	//방문은 현재 있는곳에서 갈 수 있는곳 모두(방문한 적 없고, 거리가 0 이상이여야 갈 수 있음)

	visit = setMask(visit, cur);
	if (dp[cur][visit]) {
		return dp[cur][visit];
	}

	if (visit + 1 == (1 << n)) { //모든 곳 방문
		return getDist(cur, 0);
	}

	double minValue = INT_MAX; //long long int안하면 오버플러우난다. 방문할 수 있는곳이 없는경우 int_max 반환하므로..
	for (int i = 0; i < n; i++) {
		if (isTravle(visit, i) == 1) continue;
		minValue = min(minValue, travel(i, visit) + getDist(cur,i));
	}
	
	return dp[cur][visit] = minValue;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		w[i] = { x,y };
	}

	cout.precision(17);
	cout << travel(0, 0);

	return 0;
}