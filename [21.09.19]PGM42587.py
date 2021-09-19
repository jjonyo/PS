'''
	2021.09.19
	PGM : 42587 프린터 (https://programmers.co.kr/learn/courses/30/lessons/42587)
	Algorithm : 큐
'''
from collections import deque

def solution(priorities, location):
    if len(priorities) == 1 : return 1
    answer = 0
    cnt = 0
    queue = deque()
    for i in range(len(priorities)) :
        if i == location :
            queue.append((priorities[i], 1))
        else :
            queue.append((priorities[i], 0))
    
    while queue :
        if len(queue) == 1 : return answer + 1
        prior, valid = queue.popleft()
        if prior >= max(queue)[0] :
            answer += 1
            if valid : break
        else :
            queue.append((prior, valid))
        
    return answer