import sys

N = int(sys.stdin.readline().strip())
res = None
for i in xrange(N):
	s = sys.stdin.readline().strip()
	if res==None: # pay attention, empty list will be viewed as False
		res = set(s)
	else:
		res = (set(s) & res)
	# print res

print len(res)
