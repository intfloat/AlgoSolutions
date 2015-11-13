m = int(raw_input())
num1 = map(int, raw_input().split())
n = int(raw_input())
num2 = map(int, raw_input().split())
res = list(set(num1) ^ set(num2))
res.sort()
for i in res:
	print i