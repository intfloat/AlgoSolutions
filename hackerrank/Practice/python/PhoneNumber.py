import re
n = int(raw_input())
p = re.compile('^[7-9][0-9]{9}$')
for i in range(n):
    s = raw_input()
    if p.match(s):
        print 'YES'
    else:
        print 'NO'