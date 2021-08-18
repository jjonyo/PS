'''
	2021.08.18
	BOJ : 9996 한국이 그리울땐 서버에 접속하지 (https://www.acmicpc.net/problem/9996)
	Algorithm : 문자열
'''
N = int(input())
pattern = input()
for i in range(N) :
    str = input()
    valid = True
    # 앞에서 부터
    i = 0
    replace = ""
    for c in str :
        if pattern[i] == '*' : break
        if c != pattern[i] :
            valid = False
            break
        i += 1
        replace += c
        
    
    j = len(pattern) - 1
    str = str.replace(replace, "")
    # 뒤에서
    for c in reversed(str) :
        if pattern[j] == '*' : break
        if c != pattern[j] :
            valid = False
            break
        j -= 1
    if (pattern[j] != '*') :
        valid = False
    
    print('DA' if valid else 'NE')