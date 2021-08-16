'''
    2021.08.16
    BOJ : 1388 바닥장식 (https://www.acmicpc.net/problem/1388)
    Algorithm : 그래프 탐색
'''
from collections import deque

N, M = map(int, input().split())
board = []
vis = [[0 for _ in range(M)] for _ in range(N)]
for _ in range(N) :
    board.append(input())

ans = 0
for i in range(N) :
    for j in range(M) :
        if vis[i][j] : continue
        ans += 1
        vis[i][j] = ans
        queue = deque()
        queue.append([board[i][j], i, j])
        while queue :
            c, x, y = queue.popleft()
            if c == '-' :
                nx = x
                ny = y + 1
                if nx < N and ny < M and board[nx][ny] == '-' and vis[nx][ny] == 0 :
                    vis[nx][ny] = ans
                    queue.append([board[nx][ny], nx, ny])
            elif c == '|' :
                nx = x + 1
                ny = y
                if nx < N and ny < M and board[nx][ny] == '|' and vis[nx][ny] == 0 :
                    vis[nx][ny] = ans
                    queue.append([board[nx][ny], nx, ny])
        
print(ans)