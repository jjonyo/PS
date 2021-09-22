'''
	2021.09.22
	PGM : 76502 괄호 회전하기 (https://programmers.co.kr/learn/courses/30/lessons/76502)
	Algorithm : 스택
'''
def reverse(s) :
    if s == ')' : return '('
    elif s == '}' : return '{'
    elif s == ']' : return '['

def is_correct(string) :
    stack = []
    for s in string :
        if s == '(' or s == '{' or s == '[' :
            stack.append(s)
        else :
            if stack and stack[-1] == reverse(s) :
                stack.pop()
            else :
                return False
    if stack : return False
    else : return True
    

def solution(string):
    answer = 0
    n = len(string)
    for i in range(n) :
        s = string[i:] + string[:i]
        if is_correct(s) : answer += 1
    return answer