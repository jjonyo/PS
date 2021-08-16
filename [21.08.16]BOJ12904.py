'''
	2021.08.16
	BOJ : 12904 A와 B (https://www.acmicpc.net/problem/12904)
	Algorithm : 문자열, 그리디
'''
S = input()
T = input()

length = len(S)
while True : 
	if len(T) == length :
		break
	if T[-1] == 'A' :
		T = T[:-1]
	elif T[-1] == 'B' :
		T = (T[:-1])[::-1]
print(1 if S == T else 0)