import re

N = int(raw_input())
p = re.compile('^[4|5|6][0-9]{3}-?[0-9]{4}-?[0-9]{4}-?[0-9]{4}$')
for _ in xrange(N):
    card = raw_input()
    if p.match(card) == None:
        print 'Invalid'
    else:
        ok = True
        card = card.replace('-', '')
        for i in xrange(len(card)):
            if i + 3 < len(card) and card[i] == card[i + 1] and card[i] == card[i + 2] and card[i] == card[i + 3]:
                ok = False
                break
        if ok: print 'Valid'
        else: print 'Invalid'
