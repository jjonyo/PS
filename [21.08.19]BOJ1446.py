'''
	2021.08.19
	BOJ : 1446 지름길 (https://www.acmicpc.net/problem/1446)
	Algorithm : 다이나믹프로그래밍
'''
N, D = map(int, input().split())
adj = [[] for _ in range(D + 1)]
dist = [int(1e9)] * (D + 1)
for _ in range(N) :
	a, b, d = map(int, input().split())
	if b > D : continue
	adj[b].append((d, a))
dist[0] = 0
for i in range(1, D + 1) :
	dist[i] = min(dist[i], dist[i - 1] + 1)
	for val, num in adj[i] :
		dist[i] = min(dist[i], dist[num] + val)
print(dist[D])