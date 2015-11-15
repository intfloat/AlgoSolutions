S = raw_input()
res = []
for i in xrange(len(S)):
    if (i == 0 or S[i - 1] == ' ') and S[i] >= 'a' and S[i] <= 'z':
        res.append(chr(ord(S[i]) - 32))
    else:
        res.append(S[i])
print ''.join(res)
