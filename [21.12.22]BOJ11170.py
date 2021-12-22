'''
	2021.12.22
	BOJ : 11170 0의 개수 (https://www.acmicpc.net/problem/11170)
	Algorithm : 구현
'''
T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    cnt = 0
    for i in range(N, M + 1):
        strNum = str(i)
        cnt += strNum.count('0')
    print(cnt)