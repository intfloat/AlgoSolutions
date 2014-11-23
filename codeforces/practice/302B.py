'''
Created on 2013-7-14

@author: Administrator
'''
import sys

R = lambda:map(int, raw_input().split())
n, m = R()
c, t = [], []
for i in range(n):
    cc, tt = R()
    """
    append adds an element to a list,
    however, extend concatenate the first list with the second list
    """
    c.append(cc)
    t.append(tt)
left, right, cur = 1, c[0]*t[0], 0
#print "c", c
for i in R():
    #print left, right
    if i>=left and i<=right:
        print cur+1
    else:
        while i>right:
            cur += 1
            left = right+1
            right += c[cur]*t[cur]
            #print "here", left, right
            #cur += 1
        print cur+1
    

            