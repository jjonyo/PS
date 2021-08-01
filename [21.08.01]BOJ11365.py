'''
	2021.08.01
	BOJ : 11365 !밀비 급일 (https://www.acmicpc.net/problem/11365)
	Algorithm : 문자열
'''
while True :
	str = input()
	if str == 'END' :
		break
	print(str[::-1])