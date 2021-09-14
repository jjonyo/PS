'''
	2021.09.14
	PGM : 12978 배달 (https://programmers.co.kr/learn/courses/30/lessons/12978)
	Algorithm : dijkstra
'''
import heapq

def solution(N, road, K):
    INF = int(1e9)
    adj = [[] for _ in range(N + 1)]
    dist = [INF] * (N + 1)
    for r in road :
        a, b, c = r
        adj[a].append((c, b))
        adj[b].append((c, a))
    pq = []
    heapq.heappush(pq, (0, 1))
    dist[1] = 0
    while pq :
        cur_dist, cur_num = heapq.heappop(pq)
        if cur_dist > dist[cur_num] : continue
        for nxt_dist, nxt_num in adj[cur_num] :
            next_dist = dist[cur_num] + nxt_dist
            if dist[nxt_num] > next_dist :
                dist[nxt_num] = next_dist
                heapq.heappush(pq, (next_dist, nxt_num))
    answer = 0
    for i in range(1, N + 1) :
        if dist[i] <= K : answer += 1
    return answer