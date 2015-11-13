import sys

T = int(sys.stdin.readline().strip())
for i in xrange(T):
	arr = []
	for j in xrange(4):
		x, y, z = map(int, sys.stdin.readline().strip().split())
		arr.append([x, y, z])
	vec = []
	for j in xrange(3):
		dx = arr[j+1][0] - arr[0][0]
		dy = arr[j+1][1] - arr[0][1]
		dz = arr[j+1][2] - arr[0][2]
		vec.append([dx, dy, dz])
	ci = vec[0][1]*vec[1][2] - vec[0][2]*vec[1][1]
	cj = -vec[0][0]*vec[1][2] + vec[0][2]*vec[1][0]
	ck = vec[0][0]*vec[1][1] - vec[0][1]*vec[1][0]
	res = abs(ci*vec[2][0]*1.) + abs(cj*vec[2][1]*1.) + abs(ck*vec[2][2]*1.)
	if res < 0.00001:
		print 'YES'
	else:
		print 'NO'
