#! /usr/bin/env python3
'''
' Title:	C. Soldier and Cards
' Author:	Cheng-Shih, Wong
' Date:		2016/04/17
'''

from collections import deque

n = int(input())

c1 = [int(v) for v in input().split()]
c2 = [int(v) for v in input().split()]

p1 = deque(c1[1:])
p2 = deque(c2[1:])

vis = set()
fround = 0

while len(p1)>0 and len(p2)>0 and (str(p1)+str(p2) not in vis):
	vis.add( str(p1)+str(p2) )

	u = p1.popleft()
	v = p2.popleft()

	if u > v:
		p1.extend([v, u])
	else:
		p2.extend([u, v])
	
	fround += 1

if len(p1)==0 or len(p2)==0:
	print( fround, 1 if len(p2)==0 else 2 )
else:
	print(-1)

