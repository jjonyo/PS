'''
	2021.08.14
	BOJ : 17298 오큰수 (https://www.acmicpc.net/problem/17298)
	Algorithm : 자료구조, 스택
'''
N = int(input())
lst = list(map(int, input().split()))
stack = []
ans = []
for num in reversed(lst) :
	while stack and stack[-1] <= num :
		stack.pop()
	if stack :
		ans.append(stack[-1])
	else :
		ans.append(-1)
	stack.append(num)
print(*ans)