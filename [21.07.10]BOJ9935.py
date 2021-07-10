'''
	21.07.10
	BOJ : 9935 문자열폭발 (https://www.acmicpc.net/problem/9935)
	문자열, 스택
'''
str = input()
boom = input()
stack = []
boom_len = len(boom)
for c in str :
	stack.append(c)
	if c == boom[-1] :
		if ''.join(stack[-boom_len:]) == boom :
			del stack[-boom_len:]
if not stack :
	print('FRULA')
else :
	print(''.join(stack))
