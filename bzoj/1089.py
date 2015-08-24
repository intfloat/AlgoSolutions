from math import factorial
N, D = map(int, raw_input().split())
def get(n, a):
    return factorial(n) / factorial(a) / factorial(n - a)
dp = [0] * (D + 1)
dp[0] = 1
for i in xrange(1, D + 1):
    for j in xrange(1, N + 1):
        t = sum(dp[:(i - 1)])
        dp[i] = dp[i] + get(N, j) * (dp[i - 1]**j) * (t**(N - j))
print dp[D]
