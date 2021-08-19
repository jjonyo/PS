'''
	2021.08.19
	BOJ : 14938 서강그라운드 (https://www.acmicpc.net/problem/14938)
	Algorithm : 다익스트라
'''
import heapq
n, m, r = map(int, input().split())
item = [-1] + list(map(int,input().split()))
adj = [[] for _ in range(n + 1)]
for _ in range(r) :
	a, b, val = map(int, input().split())
	adj[a].append((val, b))
	adj[b].append((val, a))

ans = 0
for i in range(n + 1) :
	heap = []
	dist = [int(2e31) for _ in range(n + 1)]
	heapq.heappush(heap, (0, i))
	while heap :
		val, cur = heapq.heappop(heap)
		if dist[cur] < val : continue
		dist[cur] = val
		for nxt_val, nxt_num in adj[cur] :
			next_dist = dist[cur] + nxt_val
			if dist[nxt_num] > next_dist :
				heapq.heappush(heap, (next_dist, nxt_num))
	sum_item = 0
	for i, d in enumerate(dist) :
		if d <= m :
			sum_item += item[i]
	ans = max(ans, sum_item)
print(ans)