'''
	2021.12.23
	BOJ : 21937 작업 (https://www.acmicpc.net/problem/21937)
	Algorithm : DFS
'''
import sys

sys.setrecursionlimit(100000)
N, M = map(int, input().split())
adj = [[] for _ in range(N + 1)]
vis = [0 for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    adj[b].append(a)
dest = int(input())

def dfs(cur): 
    if vis[cur]: return 0
    vis[cur] = 1
    cnt = 1
    for nxt in adj[cur]:
        cnt += dfs(nxt)
    return cnt

print(dfs(dest) - 1)