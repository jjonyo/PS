'''
	2021.09.21
	PGM : 12930 이상한 문자 만들기 (https://programmers.co.kr/learn/courses/30/lessons/12930)
	Algorithm : 구현
'''
def solution(s):
    words = s.split(' ')
    answer = []
    for word in words :
        temp = ''
        for i in range(len(word)) :
            if i % 2 == 0 :
                temp += word[i].upper()
            else :
                temp += word[i].lower()
        answer.append(temp)
    answer = ' '.join(answer)
    return answer