def solve(N, B, S):
    S = map(int, S.split())
    ret = 0
    for i in xrange(N):
        ret += S[i] * (B**(N - 1 - i))
    return ret

N, B = map(int, raw_input().split())
X = solve(N, B, raw_input())
N, B = map(int, raw_input().split())
Y = solve(N, B, raw_input())
if X < Y: print '<'
elif X > Y: print '>'
else: print '='
