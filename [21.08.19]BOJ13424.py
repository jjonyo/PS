'''
	2021.08.19
	BOJ : 13424 비밀 모임 (https://www.acmicpc.net/problem/13424)
	Algorithm : 다익스트라
'''
import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

T = int(input())
for _ in range(T) :
	N, M = map(int, input().split())
	adj = [[] for _ in range(N + 1)]
	for _ in range(M) :
		a, b, c = map(int, input().split())
		adj[a].append((c, b))
		adj[b].append((c, a))
	K = int(input())
	friend_rooms = map(int, input().split())
	dist = [0] * (N + 1)
	for room in friend_rooms :
		d = [INF] * (N + 1)
		heap = []
		heapq.heappush(heap, (0, room))
		d[room] = 0
		while heap :
			val, cur = heapq.heappop(heap)
			if d[cur] < val : continue
			for nxt_val, nxt_num in adj[cur] :
				next_dist = d[cur] + nxt_val
				if next_dist < d[nxt_num] :
					d[nxt_num] = next_dist
					heapq.heappush(heap,(next_dist, nxt_num))
		for i in range(N + 1) :
			dist[i] += d[i]
	min_dist = min(dist)
	print(dist.index(min_dist))