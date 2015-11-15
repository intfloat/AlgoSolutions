P = raw_input()
print   len(P) == 6 \
        and len(filter(lambda c: c < '0' or c > '9', P)) == 0 \
        and P[0] >= '1' \
        and not (P[3] == P[1] and P[2] == P[0]) \
        and not (P[4] == P[2] and P[3] == P[1]) \
        and not (P[5] == P[3] and P[2] == P[0]) \
        and not (P[5] == P[3] and P[4] == P[2])

