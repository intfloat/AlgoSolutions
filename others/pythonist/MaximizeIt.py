K, M = map(int, raw_input().split())
arr = []
for _ in xrange(K):
    arr.append(map(lambda x: abs(int(x)) % M, raw_input().split())[1:])
res = 0
def solve(pos, cur):
    global res
    if pos == len(arr):
        res = max(res, cur)
        return
    for i in arr[pos]:
        solve(pos + 1, (cur + i * i) % M)
solve(0, 0)
print res
