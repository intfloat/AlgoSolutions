# 408A.py
# straightforward implementation will work
n = int(raw_input())
k = map(int, raw_input().split())
mn = 1e9
for i in range(n):
	arr = map(int, raw_input().split())
	cur = 5*sum(arr)+15*len(arr)
	mn = min(cur, mn)
print mn