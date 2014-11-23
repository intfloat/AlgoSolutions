'''
Created on 2013-7-21

@author: Administrator
'''
n = int(raw_input())
arr = []
'''get input'''
for i in range(n):
    arr.append(str(raw_input()))
rval, cval = [-1]*n, [-1]*n
for i in range(n):
    for j in range(n):
        if arr[i][j]=='.':
            rval[i], cval[j] = j, i;
            
row, col = True, True
#print "row value", rval
#print "col value", cval
for i in range(n):
    if rval[i]==-1:
        row = False
    if cval[i]==-1:
        col = False
        
'''print result'''
if not (row==True or col==True):
    print -1
else:
    if row == True:
        for i in range(n):
            print (i+1),(rval[i]+1)
    else:
        for i in range(n):
            print (cval[i]+1),(i+1)
