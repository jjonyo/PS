'''
	2021.09.19
	PGM : 12973 짝지어 제거하기 (https://programmers.co.kr/learn/courses/30/lessons/12973)
	Algorithm : 스택
'''
def solution(string):
    answer = -1

    stack = []
    for s in string :
        if stack and stack[-1] == s :
            while stack and stack[-1] == s :
                stack.pop()
        else :
            stack.append(s)
    answer = 0 if stack else 1
    return answer