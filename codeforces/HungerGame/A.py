from fractions import gcd
from sys import stdin

def lcm(x, y):
    return x * y / gcd(x, y)

def calculate(N, p, q, k):
    if N <= 0: return 0
    ans = N / (p**k) - N / (p**(k + 1))
    ans -= N / lcm(p**k, q**k) - N / lcm(p**(k + 1), q**k)
    return ans

def solve(N, p, q):
    ans, pw = 0, 1
    while p**pw <= N:
        ans += calculate(N, p, q, pw)
        pw += 1
    return ans

l, r, p, q = map(int, stdin.readline().split())
print solve(r, p, q) - solve(l - 1, p, q)

