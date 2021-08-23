'''
	2021.08.23
	BOJ : 1707 이분 그래프 (https://www.acmicpc.net/problem/1707)
	Algorithm : BFS
	Explanation : 그래프를 두가지 값으로 구분하면 된다.
	만약 인접한 그래프가 자신과 똑같은 값을 가지고 있다면 그것은 이분그래프가 아니다.
'''
from collections import deque
K = int(input())
for _ in range(K) :
	V, E = map(int, input().split())
	adj = [[] for _ in range(V + 1)]
	color = [-1 for _ in range(V + 1)]
	for _ in range(E) :
		a, b = map(int, input().split())
		adj[a].append(b)
		adj[b].append(a)
	valid = True
	for i in range(1, V + 1) :
		if color[i] == -1 :
			Q = deque()
			color[i] = True
			Q.append(i)
			valid = True
			while Q :
				cur = Q.popleft()
				current_color = color[cur]
				for nxt in adj[cur] :
					if color[nxt] == current_color :
						valid = False
						break
					if color[nxt] != -1 : continue
					color[nxt] = not current_color
					Q.append(nxt)
			if not valid :
				break
	print('YES' if valid else 'NO')