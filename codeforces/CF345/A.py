A, B = map(int, raw_input().split())
res = 0
while A > 0 and B > 0:
    if A < 2 and B < 2:
        break
    if A < B:
        A, B = A + 1, B - 2
    else:
        A, B = A - 2, B + 1
    res += 1
print res
