
reader = file('skidesign.in', 'r')
writer = file('skidesign.out', 'w')
N = int(reader.readline())
hill = []
for i in range(N):
    hill.append(int(reader.readline()))
result = 10**8
begin = min(hill)
end = max(hill)
# enumerate all cases
for i in range(begin, end+1):
    cur = 0
    for h in hill:
        if h<i:
            cur += (h-i)**2
        elif h>(i+17):
            cur += (h-i-17)**2
    result = min([result, cur])
writer.write(str(result))
