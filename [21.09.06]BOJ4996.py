'''
	2021.09.06
	BOJ : 4999 아! (https://www.acmicpc.net/problem/4999)
	Algorithm : 문자열
'''
str = input()
prob = input()

length = len(str)
prob_length = len(prob)

if length >= prob_length :
	print('go')
else :
	print('no')