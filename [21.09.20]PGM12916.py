'''
	2021.09.19
	PGM : 12916 문자열 내 p와 y의 개수(https://programmers.co.kr/learn/courses/30/lessons/12916)
	Algorithm : 구현, 문자열 
'''
def solution(string):
    p = 0
    y = 0
    
    for s in string : 
        if s == 'p' or s == 'P' :
            p += 1
        elif s == 'y' or s == 'Y' :
            y += 1
    return True if y == p else False