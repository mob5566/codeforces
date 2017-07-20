#! /usr/bin/env python3
'''
' Title:	A. Winner
' Author:	Cheng-Shih, Wong
' Date:		2016/04/02
'''

n = int(input())
li = []
score = {}

for r in range(n):
	name, sco = input().split()
	li.append((name,int(sco)))

	if name not in score: score[name] = [0]

for i in range(n):
	for name in score:
		score[name].append(score[name][-1]+li[i][1] if name==li[i][0] else score[name][-1])

maxv = max([score[v][n] for v in score])
pos = {nm:n for nm in score}

for name in score:
	if score[name][n]!=maxv: pos[name]=n+1; continue
	for i in range(n+1):
		if score[name][i]>=maxv: pos[name]=i; break

print( min([(v,u) for u,v in pos.items()])[1] )
