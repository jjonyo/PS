'''
	2021.09.18
	PGM : 12987 숫자 게임 (https://programmers.co.kr/learn/courses/30/lessons/12987)
	Algorithm : 그리디
'''
def solution(A, B):
    A.sort()
    B.sort()
    N = len(A)
    answer = 0
    i = 0
    for n in A :
        for j in range(i, N) :
            if B[j] > n :
                i = j + 1
                answer += 1
                break
    return answer