'''
	21.07.12
	BOJ : 1543 문서검색 (https://www.acmicpc.net/problem/1543)
	브루트포스
'''
str = input()
cmp = input()

idx = 0
ans = 0
cmp_len = len(cmp)
while idx + cmp_len <= len(str) :
	tmp = str[idx:idx + cmp_len]
	if tmp == cmp :
		ans += 1
		idx += cmp_len
	else :
		idx += 1
print(ans)
