reader = open('whatbase.in', 'r')
writer = open('whatbase.out', 'w')

def get(s):
    res = []
    for c in s:
        res.append(int(c))
    return res

def compute(arr, base):    
    return arr[0] * base * base + arr[1] * base + arr[2]

K = int(reader.readline())
for _ in xrange(K):
    s1, s2 = reader.readline().split()
    n1, n2 = get(s1), get(s2)
    
    ptr1, ptr2 = 10, 10
    while ptr1 <= 15000 and ptr2 <= 15000:
        val1, val2 = compute(n1, ptr1), compute(n2, ptr2)
        if val1 == val2:
            writer.write(str(ptr1) + ' ' + str(ptr2) + '\n')
            break
        elif val1 < val2:
            ptr1 += 1
        else: ptr2 += 1
