'''
    2021.09.05
    BOJ : 13414 수강신청 (https://www.acmicpc.net/problem/13414)
    Algorithm : dictionary
'''
K, L = map(int, input().split())
dic = {}
for _ in range(L) :
    stdNum = input()
    if stdNum in dic :
        dic.pop(stdNum)
        dic[stdNum] = True
    else :
        dic[stdNum] = True
cnt = 0
for key in dic.keys() :
    if cnt == K : break
    print(key)
    cnt += 1