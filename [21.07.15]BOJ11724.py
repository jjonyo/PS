'''
	21.07.15
	BOJ : 11724 연결요소의 개수 (https://www.acmicpc.net/problem/11724)
	BFS
'''
from collections import deque

N,M = map(int,input().split())

con = [[0 for i in range(N)] for j in range(N)]
vis = [0 for i in range(N)]
for _ in range(M) :
	a, b = map(int, input().split())
	con[a - 1][b - 1] = 1
	con[b - 1][a - 1] = 1

ans = 0
queue = deque()
for i in range(N) :
	if (vis[i]) : continue
	ans += 1
	vis[i] = 1
	queue.append(i)
	while (queue) :
		cur = queue.popleft()
		for j in range(N) :
			if con[cur][j] == 0 or vis[j] : continue
			queue.append(j)
			vis[j] = 1
print(ans)