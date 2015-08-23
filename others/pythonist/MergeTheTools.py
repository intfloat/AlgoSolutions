s = raw_input()
K, N = int(raw_input()), len(s)
for i in xrange(N / K):
    cnt, res = set(), []
    for j in xrange(i * K, i * K + K):
        if not s[j] in cnt:
            res.append(s[j])
            cnt.add(s[j])
    print ''.join(res)
