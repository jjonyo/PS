'''
	2021.09.15
	PGM : 86051 없는 숫자 더하기 (https://programmers.co.kr/learn/courses/30/lessons/86051)
	Algorithm : 구현
'''
def solution(numbers):
    answer = 0
    check = [0] * 10
    for number in numbers :
        check[number] = 1
    for i in range(10) : 
        if not check[i] : answer += i
    return answer