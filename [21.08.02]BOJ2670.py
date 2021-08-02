'''
	2021.08.02
	BOJ : 2670 연속부분 최대 곱 (https://www.acmicpc.net/problem/2670)
	Algorithm : DP
'''
n = int(input())
arr = []
for _ in range(n) :
	arr.append(float(input()))

ans = arr[0]
for i in range(1, n) :
	if arr[i - 1] * arr[i] >= arr[i] :
		arr[i] = arr[i-1] * arr[i]
	ans = max(ans, arr[i])

print("%.3f" % ans)