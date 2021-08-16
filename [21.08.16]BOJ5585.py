'''
	2021.08.16
	BOJ : 5585 거스름돈 (https://www.acmicpc.net/problem/5585)
	Algorithm : 
'''
money = 1000 - int(input())
ans = 0
changes = [500, 100, 50, 10, 5, 1]

for change in changes :
	ans += int(money / change)
	money = money % change
print(ans)