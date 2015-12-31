from datetime import *
num, t1, kind = raw_input().strip().split()
num = int(num)
begin = date(2016, 1, 1)
end = date(2017, 1, 1)
res = 0
delta = timedelta(days = 1)
if kind == 'week':
    while begin < end:
        if begin.isoweekday() == num:
            res += 1
        begin += delta
else:
    while begin < end:
        if begin.day == num:
            res += 1
        begin += delta
print res
