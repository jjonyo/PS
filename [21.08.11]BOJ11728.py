'''
	2021.08.11
	BOJ : 11728 배열 합치기 (https://www.acmicpc.net/problem/11728)
	Algorithm : 정렬, 투 포인터
'''
# Solution 1 (Sort)

# N, M = map(int, input().split())
# arr1 = list(map(int,input().split()))
# arr2 = list(map(int,input().split()))
# result = arr1 + arr2
# result.sort()
# for num in result :
# 	print(num, end=' ')


# Solution 2 (Two Pointer)
N, M = map(int, input().split())
arr1 = list(map(int,input().split()))
arr2 = list(map(int,input().split()))
arr1.sort()
arr2.sort()

i = 0
j = 0
ans = []
while i < len(arr1) and j < len(arr2) :
	if arr1[i] < arr2[j] :
		ans.append(arr1[i])
		i += 1
	else :
		ans.append(arr2[j])
		j += 1

while i < len(arr1) :
	ans.append(arr1[i])
	i += 1
while j < len(arr2) :
	ans.append(arr2[j])
	j += 1
for num in ans :
	print(num, end=' ')