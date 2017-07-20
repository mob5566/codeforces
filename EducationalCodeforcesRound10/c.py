#! /usr/bin/env python3
'''
' Title:	C. Foe Pairs
' Author:	Cheng-Shih, Wong
' Date:		2016/03/26
'''

n, m = map(int, input().split())
p = [int(i) for i in input().split()]
q = [0]*(n+1)
lp = [0]*(n+1)

for i in range(n): q[p[i]] = i

for i in range(m):
	u, v = map(int, input().split())
	u, v = q[u], q[v]
	if u > v: u, v = v, u

	lp[v] = max(lp[v], u+1)
	
pos = 0
ans = 0

for i in range(n):
	pos = max(pos, lp[i])
	ans += i-pos+1

print(ans)
