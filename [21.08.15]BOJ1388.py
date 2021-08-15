from collections import deque

N, M = map(int, input().split())
board = []
vis = [[0 for _ in range(N)] for _ in range(M)]
for _ in range(M) :
    board.append(input())

ans = 0
for i in range(N) :
    for j in range(M) :
        if vis[i][j] : continue
        queue = deque()
        vis[i][j] = 1
        queue.append([board[i][j],i,j])
        ans += 1
        while queue :
            cur = queue.popleft()
            if cur[0] == '-' :
                nxt_x = cur[1]
                nxt_y = cur[2] + 1
                if vis[nxt_x][nxt_y] == 0 and nxt_y < N and board[nxt_x][nxt_y] == '-' :
                    vis[nxt_x][nxt_y] = 1
                    queue.append(['-',cur[1], cur[2] + 1])
            elif cur[0] == '|' :
                nxt_x = cur[1] + 1
                nxt_y = cur[2]
                if vis[nxt_x][nxt_y] == 0 and nxt_x < M and board[nxt_x][nxt_y] == '-' :
                    vis[nxt_x][nxt_y] = 1
                    queue.append(['-',cur[1], cur[2] + 1])

print(ans)

