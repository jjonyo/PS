'''
	2021.08.12
	BOJ : 16922 로마 숫자 만들기 (https://www.acmicpc.net/problem/16922)
	Algorithm : 백트래킹
'''
N = int(input())
ans = [[] for _ in range(N + 1)]
def dfs(cnt, total) :
	global ans
	if total in ans[cnt] :
		return
	ans[cnt].append(total)
	if cnt == N :
		return
	for num in [1,5,10,50] :
		dfs(cnt + 1, total + num)	
dfs(0,0)
print(len(ans[N]))