#! /usr/bin/env python3
'''
' Title:	B. Spreadsheets
' Author:	Cheng-Shih, Wong
' Date:		2016/03/26
'''

n = int(input())

for ti in range(n):
	s = input()

	if s[0]=='R' and s[1].isdigit() and 'C' in s:
		u, v = s[1:].split('C')
		v = int(v)
		out = []

		while v > 0:
			v -= 1
			out.append( chr(ord('A')+v%26) )
			v //= 26

		out.reverse()
		print( ''.join(out)+u )
	else:
		u = ''.join(filter(str.isalpha, s))
		v = ''.join(filter(str.isdigit, s))

		out = 0
		for c in u:
			out *= 26
			out += ord(c)-ord('A')+1
		print( 'R'+v+'C'+str(out) )
