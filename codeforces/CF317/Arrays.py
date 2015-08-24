R = lambda: map(int, raw_input().split())
na, nb = R()
K, M = R()
A, B = R(), R()
A = sorted(A)
B = sorted(B, key = lambda x: -x)
if A[K - 1] < B[M - 1]:
    print 'YES'
else:
    print 'NO'
