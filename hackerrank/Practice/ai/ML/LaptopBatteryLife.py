
import sys
import numpy as np
import matplotlib.pyplot as plt
from sklearn import linear_model

def plot_data():
	reader = open('trainingdata.txt')
	x = []
	y = []
	for line in reader:
		tx, ty = map(float, line.strip().split(','))
		x.append(tx)
		y.append(ty)

	line = plt.scatter(x, y)
	plt.show()

def train():
	reader = open('trainingdata.txt')
	feature_vector = []
	y_train = []
	x_flatten = []
	for line in reader:
		tx, ty = map(float, line.strip().split(','))
		if ty < 8.0:
			feature_vector.append([tx])
			x_flatten.append(tx)
			y_train.append(ty)
	reg = linear_model.LinearRegression()
	reg.fit(feature_vector, y_train)
	# equals to 2
	print 'coeffcients:', reg.coef_
	plt.scatter(x_flatten, y_train, color = 'black')
	plt.plot(x_flatten, reg.predict(feature_vector), color = 'blue')
	# actually we got a perfect match...
	plt.show()

def predict():
	for line in sys.stdin:
		x = float(line.strip())
		print min(2. * x, 8.0)

if __name__ == '__main__':
	#plot_data()
	#train()
	predict()
