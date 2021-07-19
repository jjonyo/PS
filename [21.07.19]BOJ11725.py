'''
	2021.07.19
	BOJ : 11725 트리의 부모 찾기 (https://www.acmicpc.net/problem/11725)
	Algorithm : 그래프탐색
'''
from collections import deque

N = int(input())
adj = [[] for i in range(N + 1)]
parent = [0 for i in range(N + 1)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

queue = deque()
parent[1] = 1
queue.append([1, 0])
while queue:
    cur, prev = queue.popleft()
    for nxt in adj[cur]:
        if (parent[nxt]):
            continue
        parent[nxt] = cur
        queue.append([nxt, cur])

for i in range(2, N + 1):
    print(parent[i])
