'''
	2021.11.01
	PGM : 12915 문자열 내 마음대로 정렬하기 (https://programmers.co.kr/learn/courses/30/lessons/12915)
	Algorithm : 
'''
def solution(strings, n) :
    strings.sort()
    answer = sorted(strings, key=lambda s: s[n])
    return answer