'''
	2021.08.09
	BOJ : 14405 피카츄 (https://www.acmicpc.net/problem/14405)
	Algorithm : 문자열
'''
def check(str) :
	for c in str :
		if c != '-':
			return False
	return True

str = input()
if str.find('-') >= 0 :
	print('NO')
	exit()
str = str.replace("pi","-")
str = str.replace("ka","-")
str = str.replace("chu","-")
if check(str):
	print('YES')
else :
	print('NO')