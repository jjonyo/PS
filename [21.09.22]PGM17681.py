'''
	2021.09.22
	PGM : 17681 비밀지도 (https://programmers.co.kr/learn/courses/30/lessons/17681)
	Algorithm : 구현, 문자열
'''
def solution(n, arr1, arr2):
    answer = ['' for _ in range(n)]
    for i in range(n) :
        binary1 = format(arr1[i], 'b').zfill(n).replace('0', ' ').replace('1', '#')
        binary2 = format(arr2[i], 'b').zfill(n).replace('0', ' ').replace('1', '#')
        for j in range(n) :
            if binary1[j] == '#' or binary2[j] == '#' :
                answer[i] += '#'
            else :
                answer[i] += ' '
        
    return answer