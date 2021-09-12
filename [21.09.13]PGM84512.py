'''
	2021.09.13
	PGM : 84512 모음 사전 (https://programmers.co.kr/learn/courses/30/lessons/84512)
	Algorithm : 
'''
words = ['A', 'E', 'I', 'O', 'U']
cnt = 0
def dfs(string, word) :
    global cnt
    if string == word :
        return cnt 
    if len(string) == 5 : 
        return 0
    for w in words :
        cnt += 1
        if dfs(string + w, word) :
            return cnt
    
    
def solution(word):
    answer = 0
    string = ''
    answer = dfs(string, word)
    return answer