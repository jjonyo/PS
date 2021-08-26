'''
	2021.08.26
	BOJ : 16928 뱀과 사다리 게임 (https://www.acmicpc.net/problem/16928)
	Algorithm : BFS
'''
from collections import deque
N, M = map(int, input().split())
board = [0 for _ in range(100 + 1)]
dist = [-1 for _ in range(100 + 1)]
for _ in range(N + M) :
	f, t = map(int, input().split())
	board[f] = t
Q = deque()
dist[1] = 0
Q.append(1)
while Q :
	cur = Q.popleft()
	if cur == 100 : break
	candidate = [cur + i for i in range(1, 7)]
	for nxt in candidate :
		if nxt > 100 or nxt < 1 : continue
		if board[nxt] != 0 :
			nxt = board[nxt]
		if dist[nxt] != -1 : continue
		dist[nxt] = dist[cur] + 1
		Q.append(nxt)
print(dist[100])