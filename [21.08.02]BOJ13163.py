'''
	2021.08.02
	BOJ : 13163 닉네임에 갓 붙이기 (https://www.acmicpc.net/problem/13163)
	Algorithm : 문자열
'''
n = int(input())
for _ in range(n) :
	str = input().split()[1::]
	print('god' + ''.join(str))