# 230B.py
n = int(raw_input())
arr = []
for i in range(n):
	row = map(int, raw_input().split())
	arr.append(row)

# print A matrix
for i in range(n):
	for j in range(n):
		print (arr[i][j]+arr[j][i])/2.0,
	print

# print B matrix
for i in range(n):
	for j in range(n):
		print (arr[i][j]-arr[j][i])/2.0,
	print
