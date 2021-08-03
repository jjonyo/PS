'''
	2021.08.03
	BOJ : 18352 특정 거리의 도시 찾기 (https://www.acmicpc.net/problem/18352)
	Algorithm : 그래프탐색
'''
from collections import deque

n, m, k, x = map(int,input().split())
adj = [[] for _ in range(n + 1)]
ans = []
dist = [-1 for _ in range(n + 1)]
for _ in range(m) :
	a, b = map(int,input().split())
	adj[a].append(b)
queue = deque()
queue.append(x)
dist[x] = 0
while queue :
	cur = queue.popleft()
	for nxt in adj[cur] :
		if dist[nxt] != -1 : continue
		queue.append(nxt)
		dist[nxt] = dist[cur] + 1

for i in range(1, n + 1) :
	if dist[i] == k :
		ans.append(i)
if ans :
	for answer in ans :
		print(answer)
else :
	print(-1)


