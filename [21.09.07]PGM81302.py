'''
	2021.09.07
	PGM : 81302 거리두기 확인하기 (https://programmers.co.kr/learn/courses/30/lessons/81302)
	Algorithm : BFS
'''
from collections import deque
dirs = [(1,0), (0, 1), (-1, 0), (0, -1)]

def BFS(i, j, place) :
	N = len(place)
	vis = [[0 for _ in range(N)] for _ in range(N)]	
	vis[i][j] = 1
	Q = deque()
	Q.append((i, j, 0))
	while Q :
		x, y, c = Q.popleft()
		if c > 2 : continue
		for dx, dy in dirs :
			nx = x + dx
			ny = y + dy
			nc = c + 1
			if nx < 0 or ny < 0 or nx >= N or ny >= N : continue
			if vis[nx][ny] : continue
			if place[nx][ny] == 'X' : continue
			if nc < 3 and place[nx][ny] =='P' : return False
			vis[nx][ny] = 1
			Q.append((nx,ny,nc))
	return True

def solution(places) :
	answer = []
	for place in places :
		N = len(place)
		valid = True
		for i in range(N) :
			for j in range(N) :
				if place[i][j] == 'P' :
					if BFS(i, j, place) == False :
						valid = False
						break
		if valid : answer.append(1)
		else : answer.append(0)
	return answer