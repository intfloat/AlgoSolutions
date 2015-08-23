GG = 10**19
sz = [0]
while sz[-1] < GG:
    sz.append(sz[-1] * 2 + 1)
R = lambda: int(raw_input().strip())
T = R()
def solve(pos, kk):
    assert(sz[pos] >= kk)
    mid = sz[pos] / 2 + 1
    if kk == mid: return 0
    elif kk < mid: return solve(pos - 1, kk)
    else:
        kk -= mid
        return 1 - solve(pos - 1, sz[pos - 1] - kk + 1)

for i in xrange(T):
    print 'Case #' + str(i + 1) + ': ',
    K = R()
    print solve(len(sz) - 1, K)
