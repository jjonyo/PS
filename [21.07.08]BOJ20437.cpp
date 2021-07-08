/*
	21.07.08
	BOJ : 20437 문자열 게임 2 (https://www.acmicpc.net/problem/20437)
	문자열
*/

#include <bits/stdc++.h>
using namespace std;

int cnt[26] = {0};
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int ans1 = INT_MAX, ans2 = 0, K;
		string str;
		cin >> str;
		cin >> K;
		fill(cnt, cnt + 26, 0);

		for (int i=0; i<str.length(); i++)
		{
			cnt[str[i] - 'a']++;
		}

		for (int i=0;i<str.length();i++)
		{
			char c = str[i];
			if (cnt[c - 'a'] < K) continue;
			int count = 0;
			for (int j=i; j< str.length(); j++)
			{
				if (str[j] == c)
					count++;
				if (count == K)
				{
					ans1 = min(ans1, j - i + 1);
					ans2 = max(ans2, j - i + 1);
					break;
				}
			}
		}
		if (ans1 == INT_MAX)
			cout << -1 << '\n';
		else
			cout << ans1 << " " << ans2 << '\n';
	}
}