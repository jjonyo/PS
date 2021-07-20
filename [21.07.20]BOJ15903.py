'''
	2021.07.20
	BOJ : 15903 카드 합체 놀이 (https://www.acmicpc.net/problem/15903)
	Algorithm : 우선순위큐
'''
import heapq

n, m = map(int, input().split())
l = map(int, input().split())
pq = []
for num in l:
    heapq.heappush(pq, num)
for _ in range(m):
    _sum = heapq.heappop(pq) + heapq.heappop(pq)
    heapq.heappush(pq, _sum)
    heapq.heappush(pq, _sum)
ans = 0
while pq:
    ans += heapq.heappop(pq)
print(ans)
