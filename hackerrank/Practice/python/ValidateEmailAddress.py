import re
from sys import stdin

pattern = re.compile('^[\w|\-]+@[0-9a-zA-Z]+\.[0-9a-zA-Z]{1,3}$')
N = int(stdin.readline().strip())
emails = []
for _ in xrange(N):
    emails.append(stdin.readline().strip())
# print [pattern.match(x) for x in emails]
res = filter(lambda x: pattern.match(x) is not None, emails)
res = sorted(res)
print res
