import sys

T = int(sys.stdin.readline().strip())
for i in xrange(T):
	px, py, qx, qy = map(int, sys.stdin.readline().strip().split())
	print 2 * qx - px, 2 * qy - py;

