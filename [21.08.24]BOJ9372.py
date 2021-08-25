'''
	2021.08.24
	BOJ : 9372 상근이의 여행 (https://www.acmicpc.net/problem/9372)
	Algorithm : 그래프 이론
'''
T = int(input())
for _ in range(T) :
	N, M = map(int, input().split())
	for _ in range(M) :
		input()
	print(N - 1)