'''
	2021.07.20
	BOJ : 2841 외계인의 기타 연주 (https://www.acmicpc.net/problem/2841)
	Algorithm : 스택
'''
N, P = map(int, input().split())
stack = [[] for _ in range(7)]
ans = 0
for _ in range(N):
    line, fret = map(int, input().split())
    while stack[line] and stack[line][-1] > fret:
        stack[line].pop(-1)
        ans += 1
    if stack[line] and stack[line][-1] == fret:
        continue
    stack[line].append(fret)
    ans += 1
print(ans)
