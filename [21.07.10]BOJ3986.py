'''
	21.07.10
	BOJ : 3986 좋은단어 (https://www.acmicpc.net/problem/3986)
	문자열, 스택
'''
n = int(input())
cnt = 0
for _ in range(n) :
	word = input()
	stack = []
	for c in word :
		if stack and stack[-1] == c :
			stack.pop()
		else :
			stack.append(c)
	if not stack :
		cnt+=1
print(cnt)