a = raw_input()
b = raw_input()
pos = 0
res = 0
while a.find(b, pos)>=0:
	res += 1
	pos = a.find(b, pos) + 1
print res