import sys

R = lambda : int(sys.stdin.readline().strip())
T = R()
for i in xrange(T):
	N = R()
	h = 1 # initial height
	for j in xrange(1, N + 1):
		if j%2 == 1:
			h = 2 * h
		else:
			h += 1
	print h