reader = open('cowroute.in', 'r')
writer = open('cowroute.out', 'w')

A, B, N = map(int, reader.readline().split())
routes, cost = [], []
for _ in xrange(N):
    c, number = map(int, reader.readline().split())
    arr = map(int, reader.readline().split())
    routes.append(arr)
    cost.append(c)
ha, hb = {}, {}

for i, arr in enumerate(routes):
    hasA = False
    for val in arr:
        if val == A: hasA = True
        elif hasA and val in ha: ha[val] = min(ha[val], cost[i])
        elif hasA and val not in ha: ha[val] = cost[i]

for i, arr in enumerate(routes):
    hasB = False
    for val in arr[-1::-1]:
        if val == B: hasB = True
        elif hasB and val in hb: hb[val] = min(hb[val], cost[i])
        elif hasB and val not in hb: hb[val] = cost[i] 

res = 10**10
# use two routes
for key in ha:
    if key in hb:
        res = min(ha[key] + hb[key], res)
if B in ha: res = min(ha[B], res) # use only one route

if res == 10**10: writer.write('-1')
else: writer.write(str(res))
