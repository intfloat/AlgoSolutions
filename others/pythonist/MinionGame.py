s = raw_input()
vowels = set(['A', 'E', 'I', 'O', 'U'])
p1, p2 = 0, 0
for i in xrange(len(s)):
    if s[i] in vowels:
        p1 += len(s) - i
    else:
        p2 += len(s) - i
if p1 > p2:
    print 'Kevin', p1
elif p1 < p2:
    print 'Stuart', p2
else:
    print 'Draw'
