'''
	2021.07.31
	BOJ : 1946 신입 사원 (https://www.acmicpc.net/problem/1946)
	Algorithm : 그리디
'''
T = int(input())
for _ in range(T) :
	list = []
	N = int(input())
	for _ in range(N) :
		a, b = map(int,input().split())
		list.append([a,b])
	list.sort(key = lambda x : x[0])
	ans = 0
	score = int(1e9)
	for cur in list :
		if cur[1] < score :
			ans += 1
			score = cur[1]
	print(ans)