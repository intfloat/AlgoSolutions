N = int(raw_input())
res = 0
for i in xrange(32):
    if (N & (1 << i)) > 0: res += 1
print res
