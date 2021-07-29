'''
	2021.07.29
	BOJ : 12852 1로 만들기 2 (https://www.acmicpc.net/problem/12852)
	Algorithm : BFS
'''
from collections import deque

n = int(input())
INF = int(1e9)
parent = [(0,INF) for _ in range(n + 1)]
Q = deque()
Q.append((n, 0))

ans = 0
while Q :
	cur, cnt = Q.popleft()
	if (cur == 1) :
		ans = cnt
		break
	if cur % 3 == 0 :
		nxt = int(cur / 3)
		if parent[nxt][1] > cnt :
			parent[nxt] = (cur, cnt)
			Q.append((nxt, cnt + 1))
	if cur % 2 == 0 :
		nxt = int (cur / 2)
		if parent[nxt][1] > cnt:
			parent[nxt] = (cur, cnt)
			Q.append((nxt, cnt + 1))
	nxt = int(cur - 1)
	if parent[nxt][1] > cnt :
		parent[nxt] = (cur, cnt)
		Q.append((nxt,cnt + 1))

print(ans)
cur = 1
order = [1,]
while parent[cur][0] :
	order.append(parent[cur][0])
	cur = parent[cur][0]
for n in order[::-1] :
	print(n,end=' ')