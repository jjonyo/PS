'''
    2021.09.17
    PGM : 49994 방문 길이 (https://programmers.co.kr/learn/courses/30/lessons/49994)
    Algorithm : 구현
'''
def reverse_dir(dir) :
    if dir == 'U' : return 'D'
    elif dir == 'D' : return 'U'
    elif dir == 'L' : return 'R'
    elif dir == 'R' : return 'L'

def solution(dirs):
    answer = 0
    vis = [[[] for _ in range(11)] for _ in range(11)]
    nxt = {'U' : [-1, 0], 'D' : [1, 0], 'L' : [0, -1], 'R' : [0, 1]}
    cur = [5, 5]
    for dir in dirs :
        i, j = cur
        ni = i + nxt[dir][0]
        nj = j + nxt[dir][1]
        if ni < 0 or nj < 0 or ni > 10 or nj > 10 : 
            continue
        cur = [ni, nj]
        if not dir in vis[ni][nj] :
            vis[i][j].append(reverse_dir(dir))
            vis[ni][nj].append(dir)
            answer += 1
        
    return answer