n = int(raw_input())
num = map(int, raw_input().split())
cur = num[0]
for i in num:
    if i >= cur:
        cur = i + 1
    else:
        cur = cur + 1
print cur - 1
