n = int(raw_input())
arr = []
for i in range(n):
	t = int(raw_input())
	if t > 0:
		arr.append(t)
unlimit = n - len(arr)
remain = n - 2 - (sum(arr) - len(arr))
res = 1
for i in range(2, n-1):
	res = res * i
for d in arr:
	for i in range(2, d):
		res = res / i
for i in range(2, remain+1):
	res = res / i
res = res * (unlimit**remain)
print res

