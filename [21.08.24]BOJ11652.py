'''
	2021.08.24
	BOJ : 11652 카드 (https://www.acmicpc.net/problem/11652)
	Algorithm : 정렬
	Explanation : 파이썬 dictionary 자료형 이용
'''
N = int(input())
dic = {}

for _ in range(N) :
    card = int(input())
    if card in dic :
        dic[card] += 1
    else :
        dic[card] = 1
max_value = max(dic.values())
ans = [n for n, v in dic.items() if v == max_value]
print(min(ans))