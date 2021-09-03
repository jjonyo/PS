'''
	2021.09.03
	PGM : (https://programmers.co.kr/learn/courses/30/lessons/)
	Algorithm : 
'''
import heapq
n, m = map(int, input().split())
adj = [[] for _ in range(n + 1)]
for _ in range(m) :
	a, b, c = map(int ,input().split())
	adj[a].append((c, b))
	adj[b].append((c, a))
p, q = map(int, input().split())
homes = list(map(int, input().split()))
stores = list(map(int, input().split()))
INF = int(1e9 * 2)
min_ans = INF
num_ans = 10000
for store in stores :
	pq = []
	dist = [INF] * (n + 1)
	heapq.heappush(pq, (0, store))
	dist[store] = 0
	while pq :
		d, cur = heapq.heappop(pq)
		if dist[cur] < d : continue
		for nxt_d, nxt_n in adj[cur] :
			next_dist = dist[cur] + nxt_d
			if dist[nxt_n] > next_dist :
				dist[nxt_n] = next_dist
				heapq.heappush(pq, (next_dist, nxt_n))
	dist[store] = INF
	min_dist = min(dist)
	if min_dist > min_ans : continue
	idx = dist.index(min_dist)
	if min_dist == min_ans :
		num_ans = min(num_ans, idx)
	else :
		num_ans = idx
		min_ans = min_dist
print(num_ans)