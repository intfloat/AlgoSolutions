from sys import stdin
import re
N = int(stdin.readline().strip())
data = ''.join(stdin.readlines())
data = data.replace('\n', '')
# remove all comments first
pattern = re.compile("<!--.*?-->")
data = pattern.sub('', data)
while True:
    x, y = data.find('<'), data.find('>')
    if x < 0 or y < 0: break
    cur = data[x + 1:y].strip()
    if cur[0] == '/':
        data = data[y + 1:]
        continue
    fs = filter(lambda x: len(x) > 0, map(lambda x: x.strip(), cur.split('"')))
    attr = fs[0].split()
    if len(attr) == 1:
        print attr[0]
    else:
        print attr[0]
        fs[0] = attr[1]
        for i in xrange(0, len(fs), 2):
            if fs[i][-1] == '=':
                print '->', fs[i][:-1], '>', fs[i + 1]
    data = data[y + 1:]
