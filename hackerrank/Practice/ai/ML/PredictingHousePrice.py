# train a simple linear regression model

import sys
from sklearn import linear_model

F, N = map(int, sys.stdin.readline().split())
feature_matrix = []
y_matrix = []
for i in xrange(N):
	ins = map(float, sys.stdin.readline().split())
	feature_matrix.append(ins[0:-1])
	y_matrix.append(ins[-1])

reg = linear_model.LinearRegression()
reg.fit(feature_matrix, y_matrix)
#print 'coefficients:', reg.coef_

T = int(sys.stdin.readline())
for i in xrange(T):
	feat = map(float, sys.stdin.readline().split())
	print reg.predict(feat)
