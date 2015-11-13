n = int(raw_input())
dict = {}
for i in range(n):
	name, s1, s2, s3 = raw_input().split()
	avg = (int(s1)+int(s2)+int(s3))/3.
	dict[name] = avg
name = raw_input()
print '%.2f' % dict[name]