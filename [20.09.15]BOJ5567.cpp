/*
	20.09.15
	BOJ : 5567 결혼식 (https://www.acmicpc.net/problem/5567)
	그래프 탐색
*/
#include <bits/stdc++.h>
using namespace std;

bool relation[501][501];
bool check[501];
int main()
{
	int N,m;
	cin >> N>>m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		relation[from][to] = 1;
		relation[to][from] = 1;
	}
	int ans = 0;
	queue <int> Q;

	for (int i = 1; i <= N; i++)
	{
		if (relation[1][i])
		{
			Q.push(i);
			check[i] = 1;
			ans++;
		}
	}
	check[1] = 1;

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for (int i = 2; i <= N; i++)
		{
			if (relation[cur][i])
			{
				if (check[i]) continue;
				check[i] = 1;
				ans++;
			}
		}
	}
	cout << ans;
}
