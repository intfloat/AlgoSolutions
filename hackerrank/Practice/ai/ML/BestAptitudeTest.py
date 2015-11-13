'''
The basic idea is to use number of inversions 
to compute ordering consistency
'''

import sys

T = int(sys.stdin.readline().strip())

for t in xrange(T):
    N = int(sys.stdin.readline().strip())
    gpa = map(float, sys.stdin.readline().strip().split())
    result = []
    for k in xrange(5):
        score = map(float, sys.stdin.readline().strip().split())
        cnt = 0
        for i in xrange(N):
            for j in xrange(i+1, N):
                val = (score[j] - score[i]) * (gpa[j] - gpa[i])
	        if val >= 0:
                    cnt += 1
        result.append(cnt)
    mx = max(result)
    ls = [e for e in xrange(len(result)) if result[e] == mx]
    print ls[0] + 1

