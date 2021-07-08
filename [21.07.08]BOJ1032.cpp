/*
	21.07.08
	BOJ : 1032 명령 프롬프트 (https://www.acmicpc.net/problem/1032)
	문자열
*/
#include <bits/stdc++.h>
using namespace std;

string str;
int main()
{
	int n;
	cin >> n;

	cin >> str;

	for (int i = 1; i < n; i++)
	{
		string s;
		cin >> s;
		for (int idx=0;idx<s.length();idx++)
		{
			if (str[idx] != s[idx])
				str[idx] = -1;
		}
	}
	for (int i=0; i < str.length(); i++)
		cout << (str[i] == -1 ? '?' : str[i]);
}