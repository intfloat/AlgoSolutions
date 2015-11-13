import sys

N, T = map(int, sys.stdin.readline().strip().split())
arr = map(int, sys.stdin.readline().strip().split())
assert(len(arr) == N)
for i in xrange(T):
	left, right = map(int, sys.stdin.readline().strip().split())
	print min(arr[left:(right + 1)])

