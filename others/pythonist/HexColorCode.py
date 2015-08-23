from sys import stdin
lines = stdin.readlines()
lines = ''.join(lines)
def ok(c):
    return (c >= 'a' and c <= 'f') or (c >= 'A' and c <= 'F') or (c >= '0' and c <= '9')
while lines.find('{') >= 0 and lines.find('}') >= 0:
    line = lines[lines.find('{'):lines.find('}')]
    while line.find('#') >= 0:
        pos = line.find('#')
        i = pos + 1
        while i < len(line) and ok(line[i]):
            i += 1
        if i - pos == 4 or i - pos == 7:
            print line[pos:i]
        line = line[pos + 1:]
    lines = lines[lines.find('}') + 1:]
