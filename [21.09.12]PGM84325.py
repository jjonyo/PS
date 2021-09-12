'''
    2021.09.12
    PGM : 84325 직업군 추천하기 (https://programmers.co.kr/learn/courses/30/lessons/84325)
    Algorithm : 구현
'''
def solution(table, languages, preference):
    answer = []
    dic = {}
    ans = []
    for info in table :
        info_list = info.split()
        dic[info_list[0]] = info_list[1::]
    for name, lst in dic.items() :
        current_score = 0
        for i in range(len(languages)) :
            lang = languages[i]
            pref = preference[i]
            if lang in lst :
                s = 5 - lst.index(lang)
            else :
                s = 0
            current_score += pref * s
        ans.append((current_score, name))
    max_score = max(ans)[0]
    for s, n in ans :
        if s == max_score :
            answer.append(n)
    answer.sort()
    return answer[0]