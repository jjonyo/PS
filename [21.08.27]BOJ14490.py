'''
	2021.08.27
	BOJ : 14490 백대열 (https://www.acmicpc.net/problem/14490)
	Algorithm : 문자열, 유클리드호제법
'''
def gcd(n, m) :
	if m == 0 : return n
	else : return gcd(m, n % m)
n, m = map(int, input().split(':'))
g = gcd(n, m)
n = int(n / g)
m = int(m / g)
print(':'.join([str(n), str(m)]))