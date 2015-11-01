from fractions import gcd
t, w, b = map(int, raw_input().split())
lcm = w * b / gcd(w, b)
up = (t / lcm) * lcm
p = (min(w, b)) * (t / lcm)
q = t
t = t - up + 1
p += min(min(w, b), t)
p -= 1
g = gcd(p, q)
p, q = p / g, q / g
print str(p) + '/' + str(q)
