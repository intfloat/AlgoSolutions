n, x = map(int, raw_input().split())
res = [1 for i in xrange(1, n + 1) if (x % i == 0) and (x / i <= n)]
print len(res)
