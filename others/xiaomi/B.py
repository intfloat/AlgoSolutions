import sys

for line in sys.stdin:
    fs = line.split()
    print(' '.join(fs[::-1]))
