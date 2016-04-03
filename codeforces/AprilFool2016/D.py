a = int(raw_input())
res = 0
while a > 0:
    res += (a % 8 == 1)
    a /= 8
print res
