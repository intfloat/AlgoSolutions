n, m = map(int, raw_input().split())
res = 0
for _ in xrange(n):
    arr = map(int, raw_input().split())
    for i in xrange(m):
        res += max(arr[2 * i], arr[2 * i + 1])
print res
