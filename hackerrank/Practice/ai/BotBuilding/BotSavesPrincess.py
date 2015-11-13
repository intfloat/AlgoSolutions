#!/bin/python
def displayPathtoPrincess(n,grid):
	#print all the moves here
	if grid[0][0] == 'p':
		x, y = 0, 0
	elif grid[0][n-1] == 'p':
		x, y = 0, n-1
	elif grid[n-1][0] == 'p':
		x, y = n-1, 0
	else:
		x, y = n-1, n-1
	if x == 0:
		for i in xrange(n/2):
			print 'UP'
	else:
		for i in xrange(n/2):
			print 'DOWN'
	if y == 0:
		for i in xrange(n/2):
			print 'LEFT'
	else:
		for i in xrange(n/2):
			print 'RIGHT'

m = input()

grid = []
for i in xrange(0, m):
    grid.append(raw_input().strip())

displayPathtoPrincess(m,grid)
