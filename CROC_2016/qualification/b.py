#! /usr/bin/env python3
'''
' Title:	B - Processing Queries
' Author:	Cheng-Shih, Wong
' Date:		2016/03/17
'''
from collections import deque

n, b = map(int, input().split())

query = {}
tm = []
que = deque()
ans = {}

for i in range(n):
	u, v = map(int, input().split())
	query[u] = v
	tm.append(u)

et = 0

for ti in tm:
	while ti>et and len(que)>0:
		cur = que.popleft()
		et += query[cur]
		ans[cur] = et

	if ti>et:
		et = ti+query[ti]
		ans[ti] = et
	elif ti==et:
		if len(que) > 0:
			cur = que.popleft()
			et = ti+query[cur]
			ans[cur] = et
		que.append(ti)
	else:
		if len(que) >= b:
			ans[ti] = -1
		else:
			que.append(ti)

while len(que)>0:
	cur = que.popleft()
	et += query[cur]
	ans[cur] = et

outs = ''
space = False

for ti in tm:
	if space: outs += ' '
	else: space = True
	outs += str(ans[ti])

print(outs)
		
