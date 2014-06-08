# 1002.py
n = map(int, raw_input().split())[0]
res = [0]*105
res[1] = 1
res[2] = 5
res[3] = 16
for i in range(4, n+1):
	res[i] = 3*res[i-1] - res[i-2] + 2
print res[n]