N = int(raw_input())
arr = raw_input().split()
K = int(raw_input())
tot, cnt = len(arr), len(filter(lambda c: c == 'a', arr))
from math import factorial
def C(n, m):
    if n < m: return 0
    else: return factorial(n) / factorial(m) / factorial(n - m)
print 1.0 - 1.0 * C(tot - cnt, K) / C(tot, K)
