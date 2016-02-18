from math import sqrt
a, b, c = map(float, raw_input().split())
r1, r2 = -b + sqrt(b * b - 4 * a * c), -b - sqrt(b * b - 4 * a * c)
r1, r2 = r1 / (2 * a), r2 / (2 * a)
print max(r1, r2)
print min(r1, r2)
