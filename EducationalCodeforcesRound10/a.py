#! /usr/bin/env python3
'''
' Title:	A. Gabriel and Caterpillar
' Author:	Cheng-Shih, Wong
' Date:		2016/03/25
'''

import math

h1, h2 = map(int, input().split())
a, b = map(int, input().split())

if h1+a*8 >= h2: print(0)
elif a <= b: print(-1)
else:
	print( math.ceil((h2-h1-8*a)/(12*(a-b))) )
