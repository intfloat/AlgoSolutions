N = int(raw_input())
row, col = [False] * N, [False] * N
for i in xrange(N * N):
    r, c = map(int, raw_input().split())
    r, c = r - 1, c - 1
    if not row[r] and not col[c]:
        row[r] = col[c] = True
        print i + 1,
print
