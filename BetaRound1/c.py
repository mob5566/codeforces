#! /usr/bin/env python3
'''
' Title:	C. Ancient Berland Circus
' Author:	Cheng-Shih, Wong
' Date:		2016/04/01
'''

import math

def vec( u, v ):
	return [u[i]-v[i] for i in range(len(u))]

def dis( u ):
	return math.sqrt(u[0]**2+u[1]**2)

def cross( u, v ):
	return (u[0]*v[1]-v[0]*u[1])

def dot( u, v ):
	return (u[0]*v[0]+u[1]*v[1])

def eq( a, b, eps=1e-3 ):
	return math.fabs(a-b) < eps

def gcd( a, b ):
	while not eq(b,0): t = b; b = a%b; a = t
	return a

p = [[float(v) for v in input().split()] for _ in range(3)]

a = dis(vec(p[0],p[1]))
b = dis(vec(p[1],p[2]))
c = dis(vec(p[2],p[0]))
S = math.fabs(0.5*cross(vec(p[1],p[0]),vec(p[2],p[0])))
R = a*b*c/(4*S)

A = math.acos((R**2-0.5*a**2)/R**2)
B = math.acos((R**2-0.5*b**2)/R**2)
C = math.acos((R**2-0.5*c**2)/R**2)

minAng = gcd(2*math.pi, gcd(A,gcd(B,C)))
#print( A/math.pi*180, B/math.pi*180, C/math.pi*180)
#print( minAng/math.pi*180, R )
n = (math.pi/minAng)

print( '{:.6f}'.format(n*R*R*math.sin(minAng)) )

