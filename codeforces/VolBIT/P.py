from math import tan, pi
n, r = map(int, raw_input().split())
ang1, ang2 = pi / n, pi / (2 * n)
num = (tan(ang1) * tan(ang2)) / (tan(ang1) + tan(ang2))
print n * r * r * num
