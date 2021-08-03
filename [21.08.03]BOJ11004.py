'''
	2021.08.03
	BOJ : 11004 K번째 수 (https://www.acmicpc.net/problem/11004)
	Algorithm : 정렬
'''
n, k = map(int, input().split())
num = list(map(int,input().split()))
num.sort()
print(num[k - 1])