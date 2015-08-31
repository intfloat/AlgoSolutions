N, M = map(int,raw_input().split()) # More than 6 lines of code will result in 0 score. Blank lines are not counted.
for i in xrange(N / 2):
    print '-' * (M / 2 - 1 - 3 * i) + '.' + '|..' * i + '|' + '..|' * i + '.' + '-' * (M / 2 - 1 - 3 * i)
print '-' * ((M - 7) / 2) + 'WELCOME' + '-' * ((M - 7) / 2)
for i in xrange(N / 2 + 1, N):
    print '-' * (M / 2 - 1 - 3 * (N - 1 - i)) + '.' + '|..' * (N - 1 - i) + '|' + '..|' * (N - 1 - i) + '.' + '-' * (M / 2 - 1 - 3 * (N - 1 - i))
