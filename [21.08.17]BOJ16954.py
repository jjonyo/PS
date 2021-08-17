'''
	2021.08.17
	BOJ : 16954 움직이는 미로 탈출 (https://www.acmicpc.net/problem/16954)
	Algorithm : BFS
'''
from collections import deque
board = []
start = (7,0)
dest = (0,7)
dirs = [(0,0), (0,1), (1,1), (1,0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1)]
for _ in range(8) :
	board.append(list(input()))
def move() :
	lst = []
	for i in range(8) :
		for j in range(8) :
			if board[i][j] == '#' :
				lst.append((i,j))
	for cur in reversed(lst) :
		i, j = cur
		board[i][j] = '.'
		if i < 7 :
			board[i + 1][j] = '#'
Q = deque()
Q.append(start)
while Q :
	todos = set()
	while Q :
		todos.add(Q.popleft())
	for todo in todos :
		x, y = todo
		if board[x][y] == '#' : continue
		if x == dest[0] and y == dest[1] :
			print(1)
			exit()
		for dir in dirs :
			nx = x + dir[0]
			ny = y + dir[1]
			if nx < 0 or nx >= 8 or ny < 0 or ny >= 8 : continue
			if board[nx][ny] == '#' : continue
			Q.append((nx,ny))
	move()
print(0)