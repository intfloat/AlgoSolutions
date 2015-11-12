K, A, B = map(int, raw_input().split())
if A > 0:
    print B / K - (A - 1) / K
elif A == 0:
    print 1 + B / K
else:
    print (-A) / K + 1 + B / K
