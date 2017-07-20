#! /usr/bin/env python3
'''
' Title:	B. The least round way
' Author:	Cheng-Shih, Wong
' Date:		2016/04/08
'''

n = int(input())
rn = range(n)
rn1 = range(1,n)
mat = [[int(s) for s in input().split()] for _ in range(n)]

def getpath( mt, pos ):
	x, y = pos
	out = []
	while mt[x][y]!=0:
		if mt[x][y]=='R':
			y -= 1
			out += ['R']
		else:
			x -= 1
			out += ['D']
	out.reverse()
	return ''.join(out)

def getfact( val, base ):
	cnt = 0
	while val%base==0: cnt+=1; val//=base
	return cnt

def getnum( val ):
	dp = [[getfact(mat[i][j],val) for j in rn] for i in rn]
	path = [[0]*n for _ in rn]

	v = mat[0][0]
	for i in rn1:
		dp[i][0] += dp[i-1][0]; path[i][0] = 'D'
		dp[0][i] += dp[0][i-1]; path[0][i] = 'R'

	for i in rn1:
		for j in rn1:
			if dp[i][j-1] > dp[i-1][j]:
				dp[i][j] += dp[i-1][j]
				path[i][j] = 'D'
			else:
				dp[i][j] += dp[i][j-1]
				path[i][j] = 'R'
	
	return dp[-1][-1], getpath(path, (n-1,n-1))

#print( *[' '.join([str(a) for a in v]) for v in mat], sep='\n' )
#print( dp )
#print(path)
	
a2, p2 = getnum(2)
a5, p5 = getnum(5)

if a2 < a5: print(a2, p2, sep='\n')
else: print(a5, p5, sep='\n')
