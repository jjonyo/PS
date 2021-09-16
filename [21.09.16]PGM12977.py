'''
	2021.09.16
	PGM : 12977 소수 만들기 (https://programmers.co.kr/learn/courses/30/lessons/12977)
	Algorithm : 소수 판별
'''
import math

def is_prime(num) :
    for i in range(2, int(math.sqrt(num)) + 1) :
        if num % i == 0 :
            return False
    return True

def solution(nums):
    N = len(nums)
    answer = 0
    for i in range(N) :
        for j in range(i + 1, N) :
            for k in range(j + 1, N) :
                num = nums[i] + nums[j] + nums[k]
                if is_prime(num) : answer += 1
    
    return answer