'''
	2021.12.17
	BOJ : 21735 눈덩이 굴리기 (https://www.acmicpc.net/problem/21735)
	Algorithm : DFS
'''
N, M = map(int, input().split())
lst = list(map(int, input().split()))

global ans
ans = 0
def dfs(snow, cur, cnt) :
    global ans
    if cnt == M or cur >= N - 1 :
        ans = max(ans, snow)
        return

    dfs(snow + lst[cur + 1], cur + 1, cnt + 1)
    if cur + 2 < N :
        dfs(snow // 2 + lst[cur + 2], cur + 2, cnt + 1)

dfs(1, -1, 0)
print(ans)