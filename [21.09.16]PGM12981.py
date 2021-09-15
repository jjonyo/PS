'''
    2021.09.16
    PGM : 12981 영어 끝말잇기 (https://programmers.co.kr/learn/courses/30/lessons/12981)
    Algorithm : 구현
'''
import math

def solution(n, words):
    answer = []
    dic = {}
    N = len(words)
    for i in range(N) :
        if len(words[i]) == 1 or words[i] in dic or (i > 0 and words[i - 1][-1] != words[i][0]) :
            f = (i + 1) % n
            if f == 0 : f = n
            s = math.ceil((i+1) / n)
            answer = [f, s]
            break
        dic[words[i]] = 1
    if not answer : answer = [0, 0]
    return answer