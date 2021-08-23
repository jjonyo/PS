'''
	2021.08.23
	BOJ : 1976 여행 가자 (https://www.acmicpc.net/problem/1976)
	Algorithm : BFS
	Explanation : N개의 도시에 대해 각각 BFS를 수행하여 A도시에서 B도시로 이동이 가능한지 기록.
	기록된 정보를 가지고 여행 계획의 순서에 맞게 방문이 가능한지 확인하면 된다.
'''
from collections import deque
N = int(input())
M = int(input())
adj = [[] for _ in range(N + 1)]
vis = [[0 for _ in range(N + 1)] for _ in range(N + 1)]
for i in range(1, N + 1) :
	adj[i].append(0)
	adj[i] += list((map(int, input().split())))
travel = list(map(int, input().split()))
for i in range(1, N + 1) :
	vis[i][i] = 1
	Q = deque()
	Q.append(i)
	while Q :
		cur = Q.popleft()
		for nxt in range(1, N + 1) :
			if adj[cur][nxt] == 0 : continue
			if vis[i][nxt] == 1 : continue
			vis[i][nxt] = 1
			Q.append(nxt)
for i in range(M - 1) :
	cur = travel[i]
	nxt = travel[i + 1]
	if vis[cur][nxt] == 0 :
		print('NO')
		exit(0)
print('YES')
