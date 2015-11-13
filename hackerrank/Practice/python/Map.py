n = int(raw_input())
if n==0:
	a = []
elif n==1:
	a = [0]
else:
	a = [0, 1]
for i in range(n-2):
    a.append(a[-1] + a[-2])
print map(lambda x : x**3, a)