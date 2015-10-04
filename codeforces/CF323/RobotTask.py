N = int(raw_input())
arr = map(int, raw_input().split())
cur, cracked, left, res = 0, [False] * N, True, 0
while cur < N:
    if left:
        for i in range(N):
            if not cracked[i] and cur >= arr[i]:
                cur += 1
                cracked[i] = True
    else:
        for i in range(N)[-1::-1]:
            if not cracked[i] and cur >= arr[i]:
                cur += 1
                cracked[i] = True
    left = not left
    res += 1
print res - 1
