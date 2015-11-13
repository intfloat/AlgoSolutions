n = int(raw_input())
a = []
for i in range(n):
	a.append(raw_input().split())
a.sort(lambda x, y : int(x[2])-int(y[2]))
for e in a:
	if e[3]=='F':
		print 'Ms. ' + e[0] + ' ' + e[1]
	else:
		print 'Mr. ' + e[0] + ' ' + e[1]
