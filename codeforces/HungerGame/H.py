from math import *
a, r1, r2 = map(int, raw_input().split())
def get(a, r):
    ang = 2.0 * asin(a / 2.0 / r)
    return (ang / 2.0) * r * r - a / 2.0 * sqrt(r * r - a * a / 4.0)
print get(a, r1) + get(a, r2)
