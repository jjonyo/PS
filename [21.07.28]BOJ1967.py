'''
	2021.07.28
	BOJ : 1325 효율적인 해킹 (https://www.acmicpc.net/problem/1325)
	Algorithm : 그래프 탐색
'''
from collections import deque

def BFS(n) :
	vis = [0 for _ in range (N + 1)]
	queue = deque()
	queue.append(n)
	vis[n] = 1
	cnt = 0
	while queue :
		cur = queue.popleft()
		for next in adj[cur] :
			if vis[next] : continue
			queue.append(next)
			vis[next] = 1
			cnt += 1
	return cnt

N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
for _ in range(M) :
	a, b = map(int, input().split())
	adj[b].append(a)

ans = [0 for _ in range(N + 1)]
for i in range(1, N + 1) :
	ans[i] = BFS(i)

max_value = max(ans)
ret = []
for index, n in enumerate(ans) :
	if n == max_value :
		print(index, end=' ')