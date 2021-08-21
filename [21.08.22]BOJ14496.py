'''
	2021.08.22
	BOJ : 14496 그대, 그머가 되어(https://www.acmicpc.net/problem/14496)
	Algorithm : BFS
'''
from collections import deque
a, b = map(int, input().split())
N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
dist = [-1] * (N + 1)
for _ in range(M) :
	f, t = map(int, input().split())
	adj[f].append(t)
	adj[t].append(f)
queue = deque()
dist[a] = 0
queue.append(a)
while queue :
	cur = queue.popleft()
	if cur == b :
		print(dist[cur])
		exit(0)
	for nxt in adj[cur] :
		if dist[nxt] != -1 : continue
		dist[nxt] = dist[cur] + 1
		queue.append(nxt)
print(-1)