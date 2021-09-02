'''
	2021.09.02
	PGM : 67256 키패드 누르기 (https://programmers.co.kr/learn/courses/30/lessons/67256)
	Algorithm : 구현
'''
def solution(numbers, hand):
	answer = ''
	#numbering
	dist = [(3,1)]
	for i in range(3) :
		for j in range(3) :
			dist.append((i,j))
	dist.append((3,0))
	dist.append((3,2))

	hand = 'R' if hand =='right' else 'L'

	current_right = 11
	current_left = 10
	for num in numbers :
		if num == 1 or num == 4 or num == 7 :
			answer += 'L'
			current_left = num
		elif num == 3 or num == 6 or num == 9 :
			answer += 'R'
			current_right = num
		else :
			left = dist[current_left]
			right = dist[current_right]
			dest = dist[num]
			left_dist = abs(dest[0] - left[0]) + abs(dest[1] - left[1])
			right_dist = abs(dest[0] - right[0]) + abs(dest[1] - right[1])
			if right_dist < left_dist :
				answer += 'R'
				current_right = num
			elif right_dist > left_dist :
				answer += 'L'
				current_left = num
			else :
				answer += hand
				if hand == 'R' : current_right = num
				else : current_left = num

	return answer