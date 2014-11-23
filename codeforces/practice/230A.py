# 230A.py
s = raw_input()
arr = [0]*200
for c in s:
	arr[ord(c)] += 1
res = min(arr[ord('e')]/3, arr[ord('i')], arr[ord('t')])
res = min(max(0, (arr[ord('n')]-1)/2), res)
print res