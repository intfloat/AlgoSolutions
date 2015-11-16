N = int(raw_input())
xs, ys = [], []
for _ in xrange(N):
    x, y = map(int, raw_input().split())
    xs.append(x)
    ys.append(y)
x1, x2, y1, y2 = min(xs), max(xs), min(ys), max(ys)
if (x2 - x1) * (y2 - y1) == 0:
    print -1
else:
    print (x2 - x1) * (y2 - y1)
