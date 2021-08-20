'''
	2021.08.20
	BOJ : 14925 목장 건설하기 (https://www.acmicpc.net/problem/14925)
	Algorithm : 다이나믹 프로그래밍
'''
M, N = map(int, input().split())
board = []
for _ in range(M) :
	board.append(list(map(int,input().split())))
dp = [[0 for _ in range(N)] for _ in range(M)]
for i in range(M) :
	for j in range(N) :
		if board[i][j] != 0 : continue
		if i == 0 or j == 0 :
			dp[i][j] = 1 if board[i][j] == 0 else 0
			continue
		elif dp[i-1][j-1] == dp[i][j-1] and dp[i][j-1] == dp[i-1][j] :
			dp[i][j] = dp[i-1][j-1] + 1
		else :
			dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
ans = 0
for d in dp :
	ans = max(ans, max(d))
print(ans)