#! /usr/bin/env python3
'''
' Title:	B. Soldier and Badges
' Author:	Cheng-Shih, Wong
' Date:		2016/04/08
'''

n = int(input())
cl = [int(v) for v in input().split()]

cl = sorted(cl)
cost = 0
has = set()
minv = 0

for v in cl:
	if v not in has: has.add(v)
	else:
		while v in has:
			v += 1
			cost += 1
		has.add(v)

print(cost)
