import random
print '10000 99997'
for i in range(10000):
	num = random.random()
	if num < 0.5:
		print 'Q', int(random.random()*i)+1
	else:
		print 'A', int(random.random()*100000.)