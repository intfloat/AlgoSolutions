reader = open('cowroute.in', 'r')
writer = open('cowroute.out', 'w')

A, B, N = map(int, reader.readline().split())
res = 10**10
for _ in xrange(N):
    cost, number = map(int, reader.readline().split())
    first = False
    arr = map(int, reader.readline().split())
    for val in arr:
        if val == A: first = True
        elif val == B and first == True: res = min(res, cost)
# print res
if res == 10**10:
    writer.write('-1')
else:
    writer.write(str(res))
