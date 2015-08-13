from math import *
a, r = map(int, raw_input().split())
ang = 2.0 * asin(a / 2.0 / r)
res = (ang / 2.0) * r * r - a / 2.0 * sqrt(r * r - a * a / 4.0)
print res
