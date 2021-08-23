'''
	2021.08.23
	BOJ : 14442 벽 부수고 이동하기 2 (https://www.acmicpc.net/problem/14442)
	Algorithm : BFS
	Explanation : 벽을 부술때마다 새로운 dist배열에 기록을 한다.
	(N, M)에 있는 dist값 중 최소값이 정답이 된다.
'''
from collections import deque
N, M, K = map(int, input().split())
INF = int(1e9)
dist = [[[INF for _ in range(M)] for _ in range(N)] for _ in range(K + 1)]
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
board = []
for _ in range(N) :
	board.append(input())
Q = deque()
dist[0][0][0] = 1
Q.append((0, 0, 0))
while Q :
	x, y, s = Q.popleft()
	if x == N - 1 and y == M - 1 : break
	for dx, dy in dirs :
		nx = x + dx
		ny = y + dy
		ns = s
		if nx < 0 or ny < 0 or nx >= N or ny >= M : continue
		if board[nx][ny] == '1' : ns += 1
		if ns > K : continue
		if dist[ns][nx][ny] != INF : continue
		dist[ns][nx][ny] = dist[s][x][y] + 1
		Q.append((nx, ny, ns))	
ans = INF
for i in range(K + 1) :
	ans = min(ans, dist[i][N - 1][M - 1])
print(-1 if ans == INF else ans)