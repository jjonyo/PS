'''
	2021.09.21
	PGM : 1844 게임 맵 최단거리 (https://programmers.co.kr/learn/courses/30/lessons/1844)
	Algorithm : BFS
'''
from collections import deque

def solution(maps):
    answer = 0
    n = len(maps)
    m = len(maps[0])
    dist = [[-1 for _ in range(m)] for _ in range(n)]
    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    queue = deque()
    dist[0][0] = 1
    queue.append((0, 0))
    while queue :
        x, y = queue.popleft()
        if x == n - 1 and y == m - 1 : break
        for nx, ny in dirs :
            nx += x
            ny += y
            if nx < 0 or ny < 0 or nx >=n or ny >= m : continue
            if dist[nx][ny] != -1 or maps[nx][ny] == 0 : continue
            dist[nx][ny] = dist[x][y] + 1
            queue.append((nx, ny))
    answer = dist[n - 1][m - 1]
    for d in dist :
        print(d)
    return answer
