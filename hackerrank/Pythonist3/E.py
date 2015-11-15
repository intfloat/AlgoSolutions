S = raw_input()
ch, cnt = '', 0
for i in xrange(len(S)):
    if S[i] != ch:
        if cnt > 0:
            print '(' + str(cnt) + ', ' + str(ch) + ')',
            ch, cnt = S[i], 1
        else:
            ch, cnt = S[i], 1
    else:
        cnt += 1
if cnt > 0:
    print '(' + str(cnt) + ', ' + str(ch) + ')'
