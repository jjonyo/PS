'''
	2021.09.10
	BOJ : 1871 좋은 자동차 번호판 (https://www.acmicpc.net/problem/1871)
	Algorithm : 문자열
'''
def convert(ss) :
	base = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
	ret = 0
	cnt = 0
	for s in reversed(ss) :
		ret += base.index(s) * (26 ** cnt)
		cnt += 1
	return ret

N = int(input())
for _ in range(N) :
	left, right = input().split('-')
	left = convert(left)
	diff = abs(left - int(right))
	if diff <= 100 :
		print('nice')
	else :
		print('not nice')
