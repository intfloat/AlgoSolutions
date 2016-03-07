n = int(raw_input())
arr = map(int, raw_input().split())
cnt = {}
for i in arr:
    if i in cnt: cnt[i] += 1
    else: cnt[i] = 1
tot = []
for key in cnt:
    tot.append(cnt[key])
sorted(tot)
res = []
while len(res) < n:
    for i in xrange(len(tot)):
        if tot[i] > 0:
            res.append(i);
            tot[i] -= 1
mx = 0
for i in xrange(1, len(res)):
    if res[i] > res[i - 1]: mx += 1
print mx
