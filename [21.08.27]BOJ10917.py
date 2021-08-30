'''
    2021.08.27
    BOJ : 10917 Your life (https://www.acmicpc.net/problem/10917)
    Algorithm : BFS
'''
from collections import deque

N, M = map(int, input().split())

adj = [[] for _ in range(N + 1)]
vis = [0 for _ in range(N + 1)]
for _ in range(M) :
    x, y = map(int, input().split())
    adj[x].append(y)
Q = deque()
Q.append((1, 0))
vis[1] = True
while Q :
    cur, score = Q.popleft()
    if cur == N :
        print(score)
        exit(0)
    for nxt in adj[cur] :
        if vis[nxt] : continue
        vis[nxt] = True
        Q.append((nxt, score + 1))
print(-1)