'''
	2021.08.13
	BOJ : 2230 수 고르기 (https://www.acmicpc.net/problem/2230)
	Algorithm : 정렬, 투 포인터
'''
N, M = map(int,input().split())
ans = int(2e31)
lst = []
for _ in range(N) :
	lst.append(int(input()))
lst.sort()
i = 0; j = 1
size = len(lst)

while i < size and j < size :
	diff = lst[j] - lst[i]
	if diff < M :
		j += 1
	else :
		ans = min(ans, diff)
		i += 1
print(ans)