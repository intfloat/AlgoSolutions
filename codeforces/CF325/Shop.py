n = int(raw_input())
R = lambda: map(int, raw_input().split())
up, low, street = R(), R(), R()
res = 10**8
for i in range(n):
    v1 = sum(up[:i]) + street[i] + sum(low[i:])
    for j in range(i + 1, n):
        v2 = sum(up[:j]) + street[j] + sum(low[j:])
        res = min(res, v1 + v2)
print res
