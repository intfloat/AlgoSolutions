# Enter your code here. Read input from STDIN. Print output to STDOUT
from sys import stdin

N = int(stdin.readline().strip())
students = []
for _ in xrange(N):
    name = stdin.readline().strip()
    score = float(stdin.readline().strip())
    students.append((score, name))

score = sorted(list(set([e[0] for e in students])))
res = []
for sc, nm in students:
    if sc == score[1]:
        res.append(nm)

res = sorted(res)
print '\n'.join(res)
