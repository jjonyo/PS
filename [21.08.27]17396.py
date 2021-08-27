'''
    2021.08.27
    BOJ : 17396 백도어 (https://www.acmicpc.net/problem/17396)
    Algorithm : 다익스트라
'''
import heapq
INF = int(2e31)
N, M = map(int, input().split())
able = list(map(int, input().split()))
adj = [[] for _ in range(N)]
dist = [INF] * N
able[N - 1] = 0

for _ in range(M) :
    a, b, t = map(int, input().split())
    if able[a] or able[b] : continue
    adj[a].append((t, b))
    adj[b].append((t, a))
pq = []
heapq.heappush(pq, (0, 0))
dist[0] = 0
while pq :
    t, cur = heapq.heappop(pq)
    if dist[cur] < t : continue
    for nxt_t, nxt_num in adj[cur] :
        next_dist = dist[cur] + nxt_t
        if dist[nxt_num] > next_dist :
            dist[nxt_num] = next_dist
            heapq.heappush(pq, (next_dist, nxt_num))
print(-1 if dist[N - 1] == INF else dist[N - 1])