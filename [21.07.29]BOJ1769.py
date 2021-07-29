'''
	2021.07.29
	BOJ : 1769 3의 배수 (https://www.acmicpc.net/problem/1769)
	Algorithm : 문자열
'''

X = input()
Y = 0
cnt = 0
while int(X) >= 10 :
	Y = 0
	for c in X :
		Y += int(c)
	X = str(Y)
	cnt += 1
print(cnt)
if int(X) % 3 == 0 :
	print('YES')
else :
	print('NO')