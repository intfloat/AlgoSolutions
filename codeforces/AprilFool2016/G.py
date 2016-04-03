F, I, T = map(int, raw_input().split())
items = [0] * I
hehe = 6
for _ in xrange(F):
    line = raw_input().strip()
    for idx, ch in enumerate(line):
        if ch == 'Y':
            items[idx] += 1
print len(filter(lambda e: e >= T, items))
