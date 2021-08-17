'''
	2021.08.17
	BOJ : 22935 이진 딸기 (https://www.acmicpc.net/problem/22935)
	Algorithm : 문자열
'''
T = int(input())

def change(s) : 
	if s == '0' :
		return 'V'
	else :
		return '딸기'

for _ in range(T) :
	N = int(input())
	N = N % 28
	if N > 15 : N = 30 - N
	if N == 0 : N = 2

	binary = str(format(N, 'b'))
	binary = list((4 - len(binary)) * '0' + binary)
	ans = list(map(change, binary))
	print(*ans, sep='')