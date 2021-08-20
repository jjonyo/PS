'''
	2021.08.21
	BOJ : (https://www.acmicpc.net/problem/)
	Algorithm : 
'''
import heapq
INF = int(1e9)
N, P, K = map(int, input().split())
adj = [[] for _ in range(N + 1)]

for _ in range(P) :
	a, b, c = map(int, input().split())
	adj[a].append((c, b))
	adj[b].append((c, a))

def dijkstra(x) :
	pq = []
	dist = [INF] * (N + 1)
	dist[1] = 0
	heapq.heappush(pq, (0, 1))
	while pq :
		val, cur = heapq.heappop(pq)
		if val > dist[cur] : continue
		for nxt_val, nxt_num in adj[cur] :
			nxt_val = 1 if nxt_val > x else 0
			nxt_dist = nxt_val + dist[cur] 
			if nxt_dist < dist[nxt_num] :
				dist[nxt_num] = nxt_dist
				heapq.heappush(pq, (nxt_dist, nxt_num))
	if dist[N] <= K : return True
	else : return False

left = 0; right = 1000000;
ans = -1
while left <= right :
	mid = (left + right) // 2

	if dijkstra(mid) :
		right = mid - 1
		ans = mid
	else :
		left = mid + 1
print(ans if ans != -1 else -1)