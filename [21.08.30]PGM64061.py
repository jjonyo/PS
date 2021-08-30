'''
	2021.08.30
	PGM : 64061 크레인 인형뽑기 게임 (https://programmers.co.kr/learn/courses/30/lessons/64061)
	Algorithm : 구현
'''

def solution(board, moves):
    answer = 0
    stack = []
    N = len(board)
    for move in moves :
        move -= 1
        idx = 0
        while idx < N :
            if board[idx][move] != 0 :
                item = board[idx][move]
                if stack and stack[-1] == item :
                    stack.pop()
                    answer += 2
                else :
                    stack.append(item)
                board[idx][move] = 0
                break
            idx += 1
    return answer