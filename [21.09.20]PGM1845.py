'''
	2021.09.19
	PGM : 1845 폰켓몬 (https://programmers.co.kr/learn/courses/30/lessons/1845)
	Algorithm : 구현
'''
def solution(nums):
    answer = 0
    new_nums = set(nums)
    N = len(nums) / 2
    if len(new_nums) > N :
        answer = N
    else :
        answer = len(new_nums)
    return answer