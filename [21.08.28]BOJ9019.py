'''
	2021.08.28
	BOJ : 9019 DSLR (https://www.acmicpc.net/problem/9019)
	Algorithm : BFS
'''
from collections import deque

oper = ['D', 'S', 'L', 'R']

def BFS(start, dest) :
	vis = [False] * 10000
	Q = deque()
	Q.append((start.zfill(4), ''))
	vis[int(start)] = True
	while Q :
		cur, ans = Q.popleft()
		if int(cur) == int(dest) :
			return ans
		for op in oper :
			if op == 'D' :
				nxt = int(cur) * 2
				if nxt > 9999 :
					nxt = nxt % 10000
			elif op == 'S' :
				nxt = int(cur) - 1
				if nxt < 0 :
					nxt = 9999
			elif op == 'L' :
				nxt = cur[1:] + cur[0]
			elif op == 'R' :
				nxt = cur[3] + cur[:3]
			if vis[int(nxt)] : continue
			vis[int(nxt)] = True
			Q.append((str(nxt).zfill(4), ans + op))
T = int(input())
for _ in range(T) :
	A, B = input().split()
	print(BFS(A,B))