n = int(raw_input())
n = n % 360
res = 0
while True:
    n = n % 360
    if n <= 45 or n >= 315:
        break
    else:
        res += 1
        n -= 90
print res
