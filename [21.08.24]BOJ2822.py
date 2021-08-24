'''
	2021.08.24
	BOJ : 2822 점수 계산 (https://www.acmicpc.net/problem/2822)
	Algorithm : 정렬
	Explanation : 정렬 후 계산
'''
scores = []
for _ in range(8) :
    scores.append(int(input()))
sort_scores = list(scores)
sort_scores.sort()
threshold = sort_scores[3]
sum_score = 0
ans = []
for i, n in enumerate(scores) :
    if n >= threshold :
        ans.append(i + 1)
        sum_score += n
print(sum_score)
print(*ans)