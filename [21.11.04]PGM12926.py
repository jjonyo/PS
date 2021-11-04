'''
	2021.11.04
	PGM : 12926 시저암호 (https://programmers.co.kr/learn/courses/30/lessons/12926)
	Algorithm : 
'''
def solution(string, n):
    answer = ''
    
    for s in string :
        if s == ' ' : 
            answer += ' '
            continue
        c = ord(s) + n
        if s.isupper() :
            if c > ord('Z') :
                c = ord('A') + c - ord('Z') - 1
        else :
            if c > ord('z') : 
                c = ord('a') + c - ord('z') - 1
        answer += chr(c)
        
        
    return answer