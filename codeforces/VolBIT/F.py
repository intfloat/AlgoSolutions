from math import factorial
def C(n, i):
    return factorial(n) / factorial(n - i) / factorial(i)
n = int(raw_input())
print C(n, 5) + C(n, 6) + C(n, 7)
