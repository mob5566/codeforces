#!/usr/bin/env python
'''
' Author:   Cheng-Shih Wong
' Email:    mob5566@gmail.com
' Date:     
'''

def main():

    def check(seq, A, B):
        fA = seq.find(A)

        return fA >= 0 and seq.find(B, fA+len(A)) >= 0

    flags = input()
    fmem = input()
    smem = input()

    forw = check(flags, fmem, smem)
    back = check(flags[::-1], fmem, smem)
    
    if forw and back:
        print('both')
    elif forw:
        print('forward')
    elif back:
        print('backward')
    else:
        print('fantasy')

if __name__ == '__main__':
    main()
