n, k = map(int, raw_input().split())
A = map(int, raw_input().split())
B = map(int, raw_input().split())
MOD = 1000000007
res = 1
for i in xrange(n / k):
    cur = (10**k - 1) / A[i] + 1
    rem = (A[i] - ((B[i] * (10**(k - 1))) % A[i])) % A[i]
    if 10**(k - 1) - 1 - rem >= 0: cur -= 1 + (10**(k - 1) - 1 - rem) / A[i]
    res = (res * cur) % MOD
print res
