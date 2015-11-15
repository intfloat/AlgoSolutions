import re

row, col = map(int, raw_input().split())
arr = []
for i in xrange(row):
    arr.append(raw_input())
    while len(arr[i]) < col:
        arr[i] += ' '
S = []
for i in xrange(col):
    for j in xrange(row):
        S.append(arr[j][i])
S = ''.join(S)
cnt, mn = 0, 0
while cnt < 5 and re.search('[a-zA-Z][!|@|#|$|%|&|\s]+[a-zA-Z]', S[mn:]) != None:
    cnt += 1
    obj = re.search('[a-zA-Z][!|@|#|$|%|&|\s]+[a-zA-Z]', S[mn:])
    l, r = obj.start() + mn, obj.end() + mn
    S = S[:l + 1] + ' ' + S[r - 1:]
    mn = l + 2
print S
