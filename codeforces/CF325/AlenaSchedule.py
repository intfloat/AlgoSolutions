n = int(raw_input())
arr = map(int, raw_input().split())
res = 0
for i in xrange(n):
    if arr[i] == 1: res += 1
    elif arr[i] == 0 and (i == 0 or arr[i - 1] == 0): continue
    elif arr[i] == 0 and (i + 1 == n or arr[i + 1] == 0): continue
    else: res += 1
print res
