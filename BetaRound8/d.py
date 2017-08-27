#!/usr/bin/env python
'''
' Author:   Cheng-Shih Wong
' Email:    mob5566@gmail.com
' Date:     2017-08-26
'''

def main():

    import math
    from itertools import combinations, chain
    EPS = 1e-12

    def fcomp(x):
        return -1 if x < -EPS else int(x>EPS)

    def dist(A, B):
        return math.sqrt((A[0]-B[0])**2+(A[1]-B[1])**2)

    def root(a, b, c):
        if fcomp(b**2-4*a*c) >= 0:
            sq = math.sqrt(b**2-4*a*c) if b**2-4*a*c > 0 else 0
            return ((-b+sq)/(2*a), (-b-sq)/(2*a))
        return None

    def circle_intersect(A, r1, B, r2):
        if fcomp(dist(A, B)-(r1+r2)) <= 0:
            if fcomp(dist(A, B)+r2-r1)<=0 or fcomp(dist(A, B)+r1-r2)<=0:
                return True, None
            else:

                a, b = A
                c, d = B
                r = r1
                s = r2
                e = c - a
                f = d - b

                p = math.sqrt(e**2+f**2)
                k = (p**2 + r**2 - s**2)/(2*p)

                if fcomp(r**2-k**2)<=0:
                    r = k

                intsec = (
                    (a+e*k/p+(f/p)*math.sqrt(r**2-k**2), b+f*k/p-(e/p)*math.sqrt(r**2-k**2)),
                    (a+e*k/p-(f/p)*math.sqrt(r**2-k**2), b+f*k/p+(e/p)*math.sqrt(r**2-k**2))
                )

                return True, intsec
        else:
            return False, None

    def check(CA, CB, CC):
        intsec = []

        if CA[1]<=0 or CB[1]<=0 or CC[1]<=0:
            return False

        for pair in combinations([CA, CB, CC], 2):
            ret, ip = circle_intersect(*pair[0], *pair[1])
            if not ret:
                return False
            intsec.append(ip)

        if None not in intsec:
            for p in chain.from_iterable(intsec):
                if fcomp(dist(p, CA[0])-CA[1])<=0 and \
                   fcomp(dist(p, CB[0])-CB[1])<=0 and \
                   fcomp(dist(p, CC[0])-CC[1])<=0:
                   return True

            return False

        return True

    def bisec(l, r):
        nonlocal A, B, C, T1, T2

        while fcomp(r-l) > 0:
            mid = (l+r)/2
            
            if check((A, mid), (B, T2-mid), (C, T1-dist(B, C)-mid)):
                l = mid
            else:
                r = mid

        return l
    
    # input
    t1, t2 = map(float, input().split())

    A, B, C = [tuple(map(float, input().split())) for _ in range(3)]

    # init
    T1 = dist(A, C)+dist(C, B)+t1
    T2 = dist(A, B)+t2

    if T2 >= dist(A, C)+dist(C, B):
        print('{0:6f}'.format(min(T1, T2)))
    else:
        print('{0:6f}'.format(bisec(0, min(T1, T2))))
        
if __name__ == '__main__':
    import sys, os
    from time import time
    if len(sys.argv)>1 and os.path.exists(sys.argv[1]):
        sys.stdin = open(sys.argv[1], 'rb')
    st = time()
    main()
    print('----- Run {:.6f} seconds. -----'.format(time()-st), file=sys.stderr)
