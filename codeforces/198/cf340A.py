gcd = lambda x, y: x+y if x*y==0 else gcd(y, x%y)
x, y, a, b = map(int, raw_input().split())
lcm = (x*y)/gcd(x, y)
print b/lcm - (a-1)/lcm
