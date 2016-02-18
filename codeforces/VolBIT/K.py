n = int(raw_input())
cnt = 0
def check(num):
    for i in xrange(2, 11):
        if num % i == 0: return False
    return True
for i in xrange(1, 2520):
    if check(i): cnt += 1
res = n / 2520 * cnt
n %= 2520
for i in xrange(1, n + 1):
    if check(i): res += 1
print res
