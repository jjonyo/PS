/*
	20.09.15
	BOJ : 1963 소수 경로 (https://www.acmicpc.net/problem/1963)
	그래프 탐색
*/
#include <bits/stdc++.h>
using namespace std;

bool isValid[10000];
int dist[10000];
int main()
{
	for (int val = 1000; val <= 9999; val++)
	{
		int ret = true;
		for (int i = 2; i <= sqrt(val); i++)
		{
			if (val % i == 0)
			{
				ret = false;
				break;
			}
		}
		if (ret)
			isValid[val] = 1;
	}
	
	int T;
	cin >> T;
	while (T--)
	{
		int start, end;
		cin >> start >> end;
		fill(dist, dist + 10000, -1);
		queue<int>Q;
		Q.push(start);
		dist[start] = 0;
		
		while (!Q.empty())
		{
			int cur = Q.front(); Q.pop();
			
			for (int i = 0; i < 4; i++)
			{
				string node = to_string(cur);
				for (int j = 0; j < 10; j++)
				{
					node[i] = j + '0';
					int next = stoi(node);
					if (next < 1000 || isValid[next] == 0 || dist[next] != -1)continue;
					Q.push(next);
					dist[next] = dist[cur] + 1;
				}
			}
		}

		if (dist[end] == -1)
			cout << "Impossible\n";
		else
			cout << dist[end]<<'\n';
	}

	

	
}
