from sys import stdin, stdout

def cnt_aux(idx, low):
    if idx == 0: return 0
    print idx
    left, right = map(int, stdin.readline().split())
    if low % 2 == 1:
        rsize = (low - 1) / 2
        lsize = cnt_aux(left, low - rsize - 1)
        return 1 + lsize + rsize
    else:
        lsize = low / 2
        rsize = cnt_aux(right, low - lsize - 1)
        return 1 + lsize + rsize

def solve(idx):
    if idx == 0: return 0
    print idx
    left, right = map(int, stdin.readline().split())
    rsize = solve(right)
    lsize = cnt_aux(left, rsize)
    return 1 + lsize + rsize

res = solve(1)
print 'Answer', res
