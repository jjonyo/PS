'''
	2021.08.08
	BOJ : 6118 숨바꼭질 (https://www.acmicpc.net/problem/6118)
	Algorithm : BFS
'''
from collections import deque

N, M = map(int, input().split())

adj = [[] for _ in range(N+1)]
dist = [-1 for _ in range(N+1)]

for _ in range(M):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)
queue = deque()
dist[1] = 0
queue.append(1)

while queue:
    cur = queue.popleft()
    for nxt in adj[cur]:
        if dist[nxt] != -1:
            continue
        dist[nxt] = dist[cur] + 1
        queue.append(nxt)
ans = []
max_dist = max(dist)
for i in range(len(dist)):
    if dist[i] == max_dist:
        ans.append(i)
print(ans[0], max_dist, len(ans))
