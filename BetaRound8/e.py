#!/usr/bin/env python
'''
' Author:   Cheng-Shih Wong
' Email:    mob5566@gmail.com
' Date:     2017-09-22
'''

def main():

    def num(left, right, dp, rev, revI):
        if left > right:
            return 1

        key = left, rev, revI
        if key in dp:
            return dp[key]
        nonlocal ans

        acc = 0

        for x in ('01' if ans[left]=='#' else ans[left]):
            
            temp = None
            if left == right:
                tmp = x
            elif ans[right]=='#':
                tmp = '01'
            else:
                tmp = ans[right]

            for y in tmp:
                if not ((rev and x>y) or (revI and x==y=='1')):
                    acc += num(
                        left+1,
                        right-1,
                        dp,
                        rev and x==y,
                        revI and x!=y
                    )
        dp[key] = acc
        return acc

    n, k = map(int, input().split())
    k += 1

    ans = ['#'] * n

    for i in range(n):
        ans[i] = '0'
        tmp = num(0, n-1, {}, True, True)

        if k > tmp:
            k -= tmp
            ans[i] = '1'

    if ans[0] == '0':
        print(''.join(ans))
    else:
        print(-1)

if __name__ == '__main__':
    import sys, os
    from time import time
    if len(sys.argv)>1 and os.path.exists(sys.argv[1]):
        sys.stdin = open(sys.argv[1], 'rb')
    st = time()
    main()
    print('----- Run {:.6f} seconds. -----'.format(time()-st), file=sys.stderr)
