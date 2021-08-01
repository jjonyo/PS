'''
	2021.08.01
	BOJ : 1159 농구 경기 (https://www.acmicpc.net/problem/)
	Algorithm : 문자열
'''
n = int(input())
dic = {}
for _ in range(n) :
	name = input()
	first = name[0]
	if first in dic :
		dic[first] += 1
	else :
		dic[first] = 1
ans = []
for f, cnt in dic.items() :
	if cnt >= 5 :
		ans.append(f)
ans.sort()
if ans :
	for c in ans :
		print(c, end='')
else :
	print('PREDAJA')