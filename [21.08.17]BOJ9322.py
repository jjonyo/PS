'''
	2021.08.17
	BOJ : 9322 철벽 보안 알고리즘(https://www.acmicpc.net/problem/9322)
	Algorithm : 문자열
'''
T = int(input())
for _ in range(T) :
	N = int(input())
	ans = ['' for _ in range(N)]
	key1 = list(input().split())
	key2 = list(input().split())
	prob = list(input().split())
	
	for i, key in enumerate(key2) :
		idx = key1.index(key)
		ans[idx] = prob[i]
	print(*ans, sep=' ')