'''
	2021.09.15
	PGM : 12982 예산 (https://programmers.co.kr/learn/courses/30/lessons/12982)
	Algorithm : 그리디
'''
def solution(d, budget):
    answer = 0
    d.sort()
    for money in d :
        if money > budget : break
        budget -= money
        answer += 1
    return answer