/*
	20.09.14
	BOJ : 2812 크게 만들기 (https://www.acmicpc.net/problem/2812)
	그리디
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N, K;
	cin >> N >> K;
	string input;
	cin >> input;

	deque <char> dq;

	int len = input.size();
	for (int i = 0; i < len; i++)
	{
		while (K && !dq.empty() && dq.back()<input[i])
		{

				dq.pop_back();
				K--;
		}
		dq.push_back(input[i]);
	}

	for (int i = 0; i < dq.size() - K; i++)
		cout << dq[i];
	
}
