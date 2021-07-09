/*
	21.07.09
	BOJ : 2776 암기왕 (https://www.acmicpc.net/problem/2776)
	자료구조
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	while (T--)
	{
		vector <int> vc;
		int n;
		cin >> n;
		for (int i=0;i<n;i++)
		{
			int num;
			cin >> num;
			vc.push_back(num);
		}

		sort(vc.begin(), vc.end());

		cin >> n;
		for (int i=0;i<n;i++)
		{
			int num;
			cin >> num;
			
			// binary search
			bool flag = false;
			int s = 0;
			int e = vc.size() - 1;
			while (s <= e)
			{
				int m = (s + e) / 2;
				if (vc[m] == num)
				{
					flag = true;
					break;
				}
				if (vc[m] > num)
					e = m - 1;
				else
					s = m + 1;
			}
			cout << flag << '\n';
		}

	}
}