#! /usr/bin/env python3
'''
' Title:	A. Soldier and Bananas
' Author:	Cheng-Shih, Wong
' Date:		2016/04/08
'''

k, n, w = [int(s) for s in input().split()]
sub = n-k*(w**2+w)//2
print( -sub if sub<0 else 0 )
