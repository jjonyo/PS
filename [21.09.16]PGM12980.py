'''
    2021.09.16
    PGM : 12980 점프와 순간 이동(https://programmers.co.kr/learn/courses/30/lessons/12980)
    Algorithm : DP
'''
def solution(n):
    ans = 0
    
    while n > 0 :
        if n % 2 == 0 :
            n /= 2
        else :
            n -= 1
            ans += 1
    return ans