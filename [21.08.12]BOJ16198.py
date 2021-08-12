'''
	2021.08.12
	BOJ : 16198 에너지 모으기 (https://www.acmicpc.net/problem/16198)
	Algorithm : 백트래킹, 브루트포스
'''
N = int(input())
lst = list(map(int,input().split()))
ans = 0

def dfs(total, lst) :
	global ans
	if len(lst) <= 2 :
		ans = max(ans, total)
		return

	for i in range(1, len(lst) - 1) :
		new_lst = [num for idx, num in enumerate(lst) if idx != i]
		new_total = total + lst[i - 1] * lst[i + 1]
		dfs(new_total, new_lst)
		
dfs(0, lst)
print(ans)