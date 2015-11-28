s = raw_input()
s = s.replace(';', ',')
arr = s.split(',')
word, d = [], []
for e in arr:
    if e.isdigit() and (e == '0' or e[0] != '0'):
        d.append(e)
    else:
        word.append(e)
if len(d) == 0:
    print '-'
else:
    print '"' + ','.join(d) + '"'
if len(word) == 0:
    print '-'
else:
    print '"' + ','.join(word) + '"'

