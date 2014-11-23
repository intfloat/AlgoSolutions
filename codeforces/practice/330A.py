'''
Created on 2013-7-21

@author: Administrator
'''
row, col = map(int, raw_input().split())
arr = []
for i in range(row):
    arr.append(str(raw_input()))
rflag, cflag = [True]*row, [True]*col
'''
    a cell will not be eaten 
    if and only if its corresponding row and column
    has a evil berry 
'''
for i in range(row):
    for j in range(col):
        if arr[i][j]=='S':
            rflag[i], cflag[j] = False, False
res = 0
for i in range(row):
    for j in range(col):
        res += (1 if (rflag[i]==True or cflag[j]==True) else 0)
print res
