from copy import deepcopy
N = int(raw_input())
row = 2 * (N - 1) + 1
col = (N - 1) * 4 + 1
arr = ['-'] * col
res = []
for _ in xrange(row): res.append(deepcopy(arr))
mr = row / 2
mc = col / 2
for i in xrange(mr + 1):
    ch = ord('a') + i
    for j in xrange(N - i):
        res[mr - i][mc - 2 * j] = chr(ch + j)
        res[mr - i][mc + 2 * j] = chr(ch + j)
        res[mr + i][mc - 2 * j] = chr(ch + j)
        res[mr + i][mc + 2 * j] = chr(ch + j)
for r in res:
    print ''.join(r)
