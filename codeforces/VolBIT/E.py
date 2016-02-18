x1, y1, x2, y2 = map(int, raw_input().split())
res = 0
def down_to_odd(x):
    if x % 2 == 0: return x - 1
    else: return x
def down_to_even(x):
    if x % 2 == 1: return x - 1
    else: return x
def up_to_odd(x):
    if x % 2 == 0: return x + 1
    else: return x
def up_to_even(x):
    if x % 2 == 1: return x + 1
    else: return x

if x1 % 2 == 0:
    x1, x2 = x1 + 1, x2 + 1
if y1 % 2 == 0:
    y1, y2 = y1 + 1, y2 + 1

low, up = up_to_odd(y1), down_to_odd(y2)
res += ((x2 - x1) / 2 + 1) * ((up - low) / 2 + 1)
low, up = up_to_even(y1), down_to_even(y2)
res += ((x2 - x1) / 2) * ((up - low) / 2 + 1)
print res
