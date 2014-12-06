
from sys import stdin

while True:
    m, n = map(int, stdin.readline().split())
    if m == -1 and n == -1:
        exit(0)
    arr = []
    for _ in xrange(n):
        j, f = map(int, stdin.readline().split())
        arr.append((j, f))
    arr.sort(key = lambda x: (1. * x[1]) / x[0])
    res = 0
    for j, f in arr:
        if m > f:
            res, m = res + j, m - f
        else:
            res += m * (1. * j / f)
            break
    print "%.3f" % res

