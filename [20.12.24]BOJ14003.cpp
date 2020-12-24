/*
    20.12.24
    BOJ : 14003 가장 긴 증가하는 부분수열5 (https://www.acmicpc.net/problem/14003)
    BFS
*/
#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
stack <int> trace;

void backtrace(int size)
{
	if (size == 0) return;
	int cur = trace.top();
	if (cur == size - 1)
	{
		int idx = trace.size()-1;
		trace.pop();
		backtrace(size - 1);
		cout << arr[idx] << ' ';
	}
	else
	{
		trace.pop();
		backtrace(size);	
	}

}

int main(void)
{
	int N;
	cin >> N;

	vector <int> list;
	int maxidx = 0;
	for (int i = 0; i < N; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);

		if (list.empty() || list.back() < arr[i])
		{
			list.push_back(arr[i]);
			trace.push(maxidx);
			maxidx++;
		}
		else
		{
			auto pos = lower_bound(list.begin(),list.end(),arr[i]);
			*pos = arr[i];
			trace.push(distance(list.begin(), pos));
		}
	}

	int size = list.size();
	cout << size << "\n";
	backtrace(size);
}
