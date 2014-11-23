import fractions
'''
the key point is to notice the problem is nothing
but compute Greatest Common Divisor of a group of numbers,
we can use python's standard library to do this
'''
n = map(int, raw_input().split())
arr = map(int, raw_input().split())
res = fractions.gcd(arr[0], arr[1])
for i in range(2, len(arr)):
    res = fractions.gcd(res, arr[i])
print res*len(arr)
