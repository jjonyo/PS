'''
	2021.08.16
	BOJ : 15904 UCPC는 무엇의 약자일까? (https://www.acmicpc.net/problem/15904)
	Algorithm : 문자열, 그리디
'''
str = input()
check = ['U', 'C', 'P', 'C']
idx = 0

for c in str :
	if idx == 4 : break
	if c == check[idx] :
		idx += 1

print('I love UCPC' if idx == 4 else 'I hate UCPC')