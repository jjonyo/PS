'''
	2021.08.11
	BOJ : 2108 통계학 (https://www.acmicpc.net/problem/2108)
	Algorithm : 구현, 정렬
'''
from collections import Counter

N = int(input())
arr = []
for _ in range(N) :
	arr.append(int(input()))
cnt = Counter(arr)
ans = []
max_cnt = max(cnt.values())
for key,values in cnt.items() :
	if values == max_cnt :
		ans.append(key)
print(round(sum(arr) / N))
print(arr[int(len(arr) / 2)])
print(ans[1] if len(ans) > 1 else ans[0])
print(max(arr) - min(arr))