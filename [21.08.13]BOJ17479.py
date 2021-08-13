'''
	2021.08.13
	BOJ : 17479 정식당 (https://www.acmicpc.net/problem/17479)
	Algorithm : 구현
'''
A, B, C = map(int, input().split())
normals = {}
specials = {}
services = []
for _ in range(A) : 
	name, price = input().split()
	normals[name] = int(price)
for _ in range(B) :
	name, price = input().split()
	specials[name] = int(price)
for _ in range(C) :
	services.append(input())

normal_total = 0
special_total = 0
service = 0

N = int(input())
for _ in range(N) :
	menu = input()
	if menu in normals :
		normal_total += normals[menu]
	elif menu in specials :
		special_total += specials[menu]
	else :
		service += 1
if special_total > 0 and normal_total < 20000 :
	print('No')
elif service > 1 or (service > 0 and normal_total + special_total < 50000) :
	print('No')
else :
	print('Okay')