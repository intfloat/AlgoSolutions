from math import factorial
def C(n, i):
    return factorial(n) / factorial(n - i) / factorial(i)
def A(n, i):
    return factorial(n) / factorial(n - i)
n = int(raw_input())
print C(n, 5) * A(n, 5)
