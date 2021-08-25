'''
	2021.08.25
	BOJ : 12851 숨바꼭질 2 (https://www.acmicpc.net/problem/12851)
	Algorithm : BFS
'''
from collections import deque
N, K = map(int, input().split())
INF = int(1e9)
dist = [INF] * (200000 + 1)
Q = deque()
Q.append((N, 0))
cnt = 0
ans = INF
while Q :
	cur, score = Q.popleft()
	if cur == K :
		if ans == INF :
			ans = score
			cnt += 1
		else :
			if score == ans :
				cnt += 1
		continue
	dist[cur] = score
	for nxt in [cur - 1, cur + 1, cur * 2] :
		if nxt > 100000 or nxt < 0 : continue
		if dist[nxt] != INF : continue
		Q.append((nxt, score + 1))
print(ans)
print(cnt)