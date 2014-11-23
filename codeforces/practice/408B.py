# 408B.py
n = raw_input()
m = raw_input()
arr1 = [0]*50
arr2 = [0]*50
for c in n:
	arr1[ord(c)-ord('a')] += 1
for c in m:
	arr2[ord(c)-ord('a')] += 1
arr = [0]*50
for i in range(50):
	if arr1[i]==0 and arr2[i]>0:
		print -1
		exit()
	arr[i] = min(arr1[i], arr2[i])
res = sum(arr)
if res == 0:
	print -1
else:
	print res