'''
Created on 2013-7-21

@author: Administrator

notice that m<n/2, so we can find a root
and construct a tree
'''

n, m = map(int, raw_input().split())
flag = [True]*(n+1)
for i in range(m):
    x, y = map(int, raw_input().split())
    flag[x]=flag[y]=False
record = [i for i in range(1, n+1) if flag[i]==True]

#print result
print n-1
for i in range(1, n+1):
    if i!=record[0]:
        print record[0], i

    
