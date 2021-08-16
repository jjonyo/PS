'''
	2021.08.16
	BOJ : 18428 감시 피하기 (https://www.acmicpc.net/problem/18428)
	Algorithm : 백트래킹
'''
N = int(input())
board = []
dirs = ['N', 'W', 'E', 'S']
for _ in range(N) :
	board.append(list(input().split()))

def edge_check(i, j) :
	if i < 0 or i >= N or j < 0 or j >= N : return True
	else : return False

def check() :
	for i in range(N) :
		for j in range(N) :
			if board[i][j] == 'T' :
				for dir in dirs :
					if dir == 'N' :
						ni = i - 1
						nj = j
						while not edge_check(ni, nj) :
							if board[ni][nj] == 'S' : return False
							if board[ni][nj] == 'O' : break
							ni -= 1
					elif dir == 'W' :
						ni = i
						nj = j - 1
						while not edge_check(ni, nj) :
							if board[ni][nj] == 'S' : return False
							if board[ni][nj] == 'O' : break
							nj -= 1
					elif dir == 'E' :
						ni = i
						nj = j + 1
						while not edge_check(ni, nj) :
							if board[ni][nj] == 'S' : return False
							if board[ni][nj] == 'O' : break
							nj += 1	
					elif dir == 'S' :
						ni = i + 1
						nj = j
						while not edge_check(ni, nj) :
							if board[ni][nj] == 'S' : return False
							if board[ni][nj] == 'O' : break
							ni += 1												
	return True				


def solve(cnt, x, y) :
	if cnt == 3 :
		if check() :
			print('YES')
			exit()
		return
	i = x
	j = y
	while i < N :
		while j < N :
			if board[i][j] == 'X' :
				board[i][j] = 'O'
				solve(cnt + 1, i, j)
				board[i][j] = 'X'
			j += 1
		j = 0
		i += 1
	
for i in range(N) :
	for j in range(N) :
		if board[i][j] == 'X' :
			board[i][j] = 'O'
			solve(1, i, j)
			board[i][j] = 'X'
print('NO')