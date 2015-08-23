s = raw_input()
cnt = {}
for c in s:
    if c in cnt: cnt[c] += 1
    else: cnt[c] = 1
cand = cnt.keys()
def f(x, y):
    if cnt[x] < cnt[y]: return 1
    elif cnt[x] > cnt[y]: return -1
    else: return ord(x) - ord(y)

cand = sorted(cand, cmp = f)
for i in xrange(3):
    print cand[i], cnt[cand[i]]
