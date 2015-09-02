from datetime import *
T = int(raw_input())
def solve():
    d1, m1, y1, d2, m2, y2 = map(int, raw_input().split())
    begin = date(y1, m1, d1)
    end = date(y2, m2, d2)
    res = 0
    delta1, delta7 = timedelta(days = 1), timedelta(days = 7)
    while begin <= end:
        try:
            if begin.isoweekday() == 5:
                if begin.day == 13:
                    res += 1
                begin += delta7
            else:
                begin += delta1
        except:
            break
    print res
for _ in xrange(T):
    solve()
