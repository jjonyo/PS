'''
	2021.08.11
	BOJ : 1789 수들의 합 (https://www.acmicpc.net/problem/1789)
	Algorithm : 그리디
'''
S =  int(input())
i = 0
_sum = 0
while True :
    _sum += i
    if _sum > S :
        break
    i += 1
print(i - 1)