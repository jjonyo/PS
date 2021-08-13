'''
	2021.08.13
	BOJ : 10451 순열 사이클 (https://www.acmicpc.net/problem/10451)
	Algorithm : 그래프탐색, BFS
'''
from collections import deque
T = int(input())

for _ in range(T) : 
	N = int(input())
	lst = list(map(int, input().split()))
	adj = [0 for _ in range(N + 1)]
	vis = list(adj)
	ans = 0
	for i in range(1, N + 1) :
		adj[i] = lst[i - 1]
	for i in range(1, N + 1) :
		if vis[i] : continue
		ans += 1
		queue = deque()
		queue.append(i)
		vis[i] = 1
		while queue :
			cur = queue.popleft()
			nxt = adj[cur]
			if vis[nxt] : continue
			vis[nxt] = 1
			queue.append(nxt)
	print(ans)
	