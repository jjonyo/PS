'''
	2021.12.19
	BOJ : 1326 폴짝폴짝 (https://www.acmicpc.net/problem/1326)
	Algorithm : BFS
'''
from collections import deque

N = int(input())
arr = [0] + list(map(int, input().split()))
a, b = map(int, input().split())

INF = int(1e9)
dist = [INF for _ in range(N + 1)]
Q = deque()
dist[a] = 0
Q.append(a)

while Q :
    cur = Q.popleft()
    num = arr[cur]
    if cur == b :
        break
    for i in range(1, 10001) :
        nxt = cur + num * i
        if nxt > N : break
        Q.append(nxt)
        dist[nxt] = min(dist[nxt], dist[cur] + 1)
    for i in reversed(range(-10000, 0)) :
        nxt = cur + num * i
        if nxt < 1 : break
        Q.append(nxt)
        dist[nxt] = min(dist[nxt], dist[cur] + 1)
print(dist[b]) if dist[b] != INF else print(-1)