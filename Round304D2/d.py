#! /usr/bin/env python3
'''
' Title:	D. Soldier and Number Game
' Author:	Cheng-Shih, Wong
' Date:		2016/04/17
'''

prime = []
isp = [True]*5001

for i in range(2,5001):
	if not isp[i]: continue
	prime.append(i)
	for j in range(i+i,5001,i): isp[j] = False

acc = [0]*5000001

for i in range(2,5000001):
	val = i
	
	for p in prime:
		if p > val: break
		while val%p==0: val//=p; acc[i]+=1
	
	if val!=1: acc[i]+=1
	acc[i] += acc[i-1]

print("done")
t = int(input())

for ti in range(t):
	a, b = [int(v) for v in input().split()]
	
	print( acc[a]-acc[b] )
