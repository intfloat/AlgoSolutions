from fractions import gcd
N, a, b = map(int, raw_input().split())
g = gcd(a, b)
print str(N) * g
