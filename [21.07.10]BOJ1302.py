'''
	21.07.10
	BOJ : 1302 베스트셀러 (https://www.acmicpc.net/problem/1302)
	문자열
'''

n = int(input())
dic = {}
for _ in range(n) :
	title = input()
	if title in dic :
		dic[title] += 1
	else :
		dic[title] = 1
max_ans = max(dic.values())
ans = []
for book, val in dic.items() :
	if val == max_ans :
		ans.append(book)
ans = sorted(ans)
print(ans[0])