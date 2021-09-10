'''
	2021.09.10
	BOJ : 4470 줄 번호(https://www.acmicpc.net/problem/4470)
	Algorithm : 문자열
'''
N = int(input())
for i in range(N) :
	s = input()
	s = str(i + 1) + '. ' + s
	print(s)