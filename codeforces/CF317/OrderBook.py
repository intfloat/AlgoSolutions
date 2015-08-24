R = lambda: raw_input().split()
n, s = map(int, R())
buy, sell = {}, {}
for _ in xrange(n):
    record = R()
    p, v = map(int, record[1:])
    if record[0] == 'B':
        if p in buy: buy[p] += v
        else: buy[p] = v
    elif record[0] == 'S':
        if p in sell: sell[p] += v
        else: sell[p] = v
arr = sell.keys()
arr = sorted(arr)
for key in arr[s - 1::-1]:
    print 'S', key, sell[key]
arr = buy.keys()
arr = sorted(arr, key = lambda x: -x)
for key in arr[:s]:
    print 'B', key, buy[key]
