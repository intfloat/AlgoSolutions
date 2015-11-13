import sys

T = int(sys.stdin.readline().strip())
for i in xrange(T):
	r1, r2, = map(int, sys.stdin.readline().strip().split())
	x1, y1, z1 = map(int, sys.stdin.readline().strip().split())
	ax1, ay1, az1 = map(int, sys.stdin.readline().strip().split())
	x2, y2, z2 = map(int, sys.stdin.readline().strip().split())
	ax2, ay2, az2 = map(int, sys.stdin.readline().strip().split())
	ax2 -= ax1
	ay2 -= ay1
	az2 -= az1
	x1 -= x2
	y1 -= y2
	z1 -= z2
	inner = x1*ax2 + y1*ay2 + z1*az2
	if inner <= 0:
		print 'NO'
		continue
	ci = ay2*z1 - az2*y1
	cj = -(ax2*z1 - az2*x1)
	ck = ax2*y1 - ay2*x1
	cur = (ci**2 + cj**2 + ck**2) * 1.
	cur = cur**0.5
	den = (ax2**2 + ay2**2 + az2**2) * 1.
	den = den**0.5
	cur = cur / den
	if (cur - r1 - r2) < 0.00001:
		print 'YES'
	else:
		print 'NO'
