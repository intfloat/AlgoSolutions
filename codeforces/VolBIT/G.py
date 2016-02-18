n = int(raw_input())
def solve(tot, num):
    dp = [[0 for _ in xrange(num + 1)] for _ in xrange(tot + 1)]
    dp[0][0] = 1
    for i in xrange(1, tot + 1):
        for j in xrange(0, num + 1):
            for k in xrange(0, j + 1):
                dp[i][j] += dp[i - 1][j - k]
    return dp[tot][num]
print solve(n, 5) * solve(n, 3)
