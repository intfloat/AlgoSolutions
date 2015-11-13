#!/usr/bin/python
def nextMove(posr, posc, board):
	for i in xrange(len(board)):
		for j in xrange(len(board[i])):		
			if board[i][j] == 'd':
				# print board[i][0]
				x, y = i, j
				if posr < x:
					print 'DOWN'
				elif posr > x:
					print 'UP'
				elif posc < y:
					print 'RIGHT'
				elif posc > y:
					print 'LEFT'
				else:
					print 'CLEAN'
				return
    # print ""

if __name__ == "__main__":
    pos = [int(i) for i in raw_input().strip().split()]
    board = [[j for j in raw_input().strip()] for i in range(5)]
    nextMove(pos[0], pos[1], board)
