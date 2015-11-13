import sys
from sklearn import linear_model

F = N = T = 0
x_train = []
y_train = []
reg = linear_model.LinearRegression()

def read_data():	
	F, N = map(int, sys.stdin.readline().strip().split())
	for i in xrange(N):
		ins = map(float, sys.stdin.readline().strip().split())
		y_train.append(ins[-1])
		x_ins = []
		# use three order polynomial functions to fit data
		for num in ins[0:-1]:
			x_ins.append(num)
			x_ins.append(num**2)
			x_ins.append(num**3)
		x_train.append(x_ins)
	pass

def train():
	global reg	
	reg.fit(x_train, y_train)
	# print 'coefficients: ', reg.coef_
	pass

def predict():
	T = int(sys.stdin.readline().strip())
	for i in xrange(T):
		arr = map(float, sys.stdin.readline().strip().split())
		x_test = []
		for num in arr:
			x_test.append(num)
			x_test.append(num**2)
			x_test.append(num**3)
		print reg.predict(x_test)
	pass

if __name__ == '__main__':
	# print 'start reading data'
	read_data()
	# print 'start training models'
	train()
	# print 'start predict phase'
	predict()
	# print 'task finished'