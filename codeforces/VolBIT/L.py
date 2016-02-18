n = raw_input().strip()
n = int(''.join([n[0], n[2], n[4], n[3], n[1]]))
res = str((n**5) % 100000)
while len(res) < 5:
    res = '0' + res
print res
