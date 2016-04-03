line = raw_input().strip()
res = 0
for ch in line:
    res += (ord(ch) - ord('A') + 1 if ch.isupper() else 0)
    res -= (ord(ch) - ord('a') + 1 if ch.islower() else 0)
print res
