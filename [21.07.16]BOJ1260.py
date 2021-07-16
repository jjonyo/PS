'''
	2021.07.16
	BOJ : 1260 DFS와 BFS(https://www.acmicpc.net/problem/1260)
	Algorithm : BFS,DFS
'''
from collections import deque

N,M,V = map(int,input().split())
con = [[0 for i in range(N)] for j in range(N)]
vis = [0 for _ in range(N)]

for _ in range(M) :
	a,b = map(int, input().split())
	con[a-1][b-1] = 1
	con[b-1][a-1] = 1

def DFS(cur) :
	if vis[cur] : return
	vis[cur] = 1
	print(cur + 1,end=' ')
	for i in range(N) :
		if (con[cur][i] == 0 or vis[i]) : continue
		DFS(i)

def BFS(start) :
	queue = deque()
	vis[start] = 1
	queue.append(start)
	while queue :
		cur = queue.popleft()
		print(cur + 1,end=' ')
		for i in range(N) :
			if con[cur][i] == 0 or vis[i] : continue
			vis[i] = 1
			queue.append(i)
	
DFS(V - 1)
print()
vis = [0 for _ in range(N)]
BFS(V - 1)