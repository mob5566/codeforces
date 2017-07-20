#! /usr/bin/env python3
'''
' Title:	A. Parliament of Berland
' Author:	Cheng-Shih, Wong
' Date:		2016/03/17
'''

n, a, b = map(int, input().split())

if n > a*b:
	print(-1)
else:
	for i in range(a):
		s = []

		for j in range(b):
			s.append(n)
			if n > 0: n -= 1

		if i&1 == 1:
			s.reverse()

		print( ' '.join(str(v) for v in s) )
