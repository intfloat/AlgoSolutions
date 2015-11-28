from math import *
x1, y1, r1 = map(float, raw_input().split())
x2, y2, r2 = map(float, raw_input().split())
d = sqrt((x1 - x2)**2 + (y1 - y2)**2)
if r1 > r2:
    r1, r2 = r2, r1

if d >= (r1 + r2):
    print 0
    exit(0)
if d <= r2 - r1:
    print pi * r1**2
    exit(0)
if d > r2 - r1 and d < r2:
    c1 = acos((-r1 * r1 + d * d + r2 * r2) / (2.0 * d * r2))
    c2 = pi - acos((-r2 * r2 + d * d + r1 * r1) / (2.0 * d * r1))
    area = c1 * r2 * r2 - r2 * r2 * cos(c1) * sin(c1)
    area += r1 * r1 * cos(c2) * sin(c2)
    area += r1 * r1 * (pi - c2)
    print area
    exit(0)
ctheta = (-r1 * r1 + d * d + r2 * r2) / (2.0 * r2 * d)
c = acos(ctheta)
area = c * r2 * r2
area -= r2 * r2 * 0.5 * sin(2.0 * c)
r1, r2 = r2, r1
ctheta = (-r1 * r1 + d * d + r2 * r2) / (2.0 * r2 * d)
c = acos(ctheta)
area += c * r2 * r2
area -= r2 * r2 * 0.5 * sin(2.0 * c)
print area
