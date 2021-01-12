/*
	21.01.12
	BOJ 2517 : 달리기 (https://www.acmicpc.net/problem/2157)
	inversion count
*/
#include <bits/stdc++.h>
using namespace std;

class Runner {
public:
	int stat;
	int inversion;
	int position;
};

Runner arr[500001] = { 0 };
Runner temp[500001] = { 0 };

void merge(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i].stat >= arr[j].stat)
			temp[k++] = arr[i++];
		else {
			arr[j].inversion += mid - i + 1;
			temp[k++] = arr[j++];
		}
	}

	int tmp = i > mid ? j : i;

	while (k <= right) temp[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = temp[i];
}

void partition(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

bool cmp(Runner& a, Runner& b) {
	return a.position < b.position;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i].stat;
		arr[i].inversion = 0;
		arr[i].position = i;
	}

	partition(1, N);

	sort(arr, arr + N + 1, cmp);

	for (int i = 1; i <= N; i++) {
		cout << arr[i].position - arr[i].inversion << '\n';
	}

	return 0;
}