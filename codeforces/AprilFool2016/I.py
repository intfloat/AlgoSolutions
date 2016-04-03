line = raw_input().strip()[1:]
res = 1
for ch in line:
    res += (9 if ch == '0' else ord(ch) - ord('0'))
print res
