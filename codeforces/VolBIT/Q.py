from math import *
a, b, c = map(float, raw_input().split())
res = sqrt(2.0) / 12 * a**3
res += sqrt(2.0) / 6 * b**3
res += c**3 / 24 * sqrt(25 + 10.0 * sqrt(5)) * sqrt(3.0 - tan(54 / 180. * pi)**2)
print res
