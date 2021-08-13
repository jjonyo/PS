'''
	2021.08.13
	BOJ : 5597 (https://www.acmicpc.net/problem/5597)
	Algorithm : 구현
'''
attendance = [n for n in range(1, 31)]
for _ in range(28) :
	num = int(input())
	attendance.remove(num)
for n in attendance :
	print(n)
