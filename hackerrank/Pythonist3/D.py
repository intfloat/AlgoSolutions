S = raw_input()
def get(x):
    if x >= 'a' and x <= 'z':
        return 0
    elif x >= 'A' and x <= 'Z':
        return 1
    else:
        num = ord(x) - ord('0')
        if num % 2 == 1: return 3
        else: return 4

def mycmp(x, y):
    xx, yy = get(x), get(y)
    if xx != yy:
        if xx < yy: return -1
        else: return 1
    elif x < y: return -1
    else: return 1

res = ''
def rfunc(x, y):
    global res
    if len(res) == 0:
        res += x
        res += y
    else:
        res += y
    return ''
reduce(rfunc, sorted(S, cmp = mycmp))
print res
