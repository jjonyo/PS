'''
	2021.09.04
	BOJ : 10821 정수의 개수 (https://www.acmicpc.net/problem/10821)
	Algorithm : 문자열
'''
lst = input().split(',')
ans = 0
for w in lst :
	if w.isnumeric() :
		ans += 1
print(ans)