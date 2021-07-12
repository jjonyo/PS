'''
	21.07.12
	BOJ : 1743 음식물 피하기 (https://www.acmicpc.net/problem/1743)
	BFS
'''
from collections import deque

N,M,K = map(int,input().split())
board = [[0 for _ in range(M)] for _ in range(N)]
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

for _ in range(K) :
	a, b = map(int, input().split())
	board[a-1][b-1] = 1

ans = 0
for i in range(N) :
	for j in range(M) :
		if board[i][j] :
			queue = deque()
			queue.append((i,j))
			board[i][j] = 0
			size = 1
			while queue :
				x,y = queue.popleft()
				for dir in range(4) :
					nx = x + dx[dir]
					ny = y + dy[dir]
					if (nx < 0 or ny < 0 or nx >= N or ny >= M) : continue
					if board[nx][ny] == 0 : continue
					queue.append([nx,ny])
					board[nx][ny] = 0
					size += 1
			ans = max(ans,size)
print(ans)