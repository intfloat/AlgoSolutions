#!/bin/python
pr = -1; pc = -1 # position of princess
def nextMove(n,r,c,grid):
	assert(pr >= 0)
	assert(pc >= 0)
	if r < pr:
		return 'DOWN'
	elif r > pr:
		return 'UP'
	if c < pc:
		return 'RIGHT'
	elif c > pc:
		return 'LEFT'
    

n = input()
r,c = [int(i) for i in raw_input().strip().split()]
grid = []
for i in xrange(0, n):
    grid.append(raw_input())
    if grid[-1].find('p') >= 0:
    	pr = i
    	pc = grid[-1].index('p')

print nextMove(n,r,c,grid)
