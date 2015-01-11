
# use generating function to solve this problem
import sys

N = int(sys.stdin.readline().strip())
res = (N * (N + 1) * (N + 2)) / 6
print res % 10007
