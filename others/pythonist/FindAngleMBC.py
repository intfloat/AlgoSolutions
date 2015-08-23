from math import *
AB = float(raw_input())
BC = float(raw_input())
a, b, c = sqrt(AB**2 + BC**2) / 2, BC, sqrt(AB**2 + BC**2) / 2
res = acos((a * a + b * b - c * c) / (2 * a * b))
res = res / pi * 180.0
print str(int(round(res))) + '°'
