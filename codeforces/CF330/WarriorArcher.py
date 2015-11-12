N = int(raw_input())
arr = sorted(map(int, raw_input().split()))
print min([arr[i + N / 2] - arr[i] for i in xrange(N / 2)])
