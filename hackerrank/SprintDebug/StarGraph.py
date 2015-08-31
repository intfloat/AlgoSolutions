
#Python 2
N = 300
INF = 10000000

def fordFulkerson(n, s, t, cap):
    # init the flow network
    fnet = [0] * (N*N)
    q = [0] * N
    prv = [0] * N
    flow = 0
    while True:
        # find an augmenting path
        prv = [-1] * N
        qf, qb = 0, 0
        q[qb] = s
        qb += 1
        prv[s] = -2
        while qb > qf and prv[t] == -1:
            u = q[qf]
            qf += 1
            for v in range(n):
                if prv[v] == -1 and fnet[u+v * N] < cap[u+v * N]:
                    q[qb] = v
                    qb += 1
                    prv[v] = u
        # see if we're done
        if prv[t] == -1: break
        # get the bottleneck capacity
        bot = 0x7FFFFFFF
        v = t
        u = prv[v]
        while u >= 0:
            bot = min(bot, cap[u+v * N] - fnet[u+v * N])
            v = u
            u = prv[v]
        # update the flow network
        v = t
        u = prv[v]
        while u >= 0:
            fnet[u+v * N], fnet[v + N * u] = fnet[u + v * N] + bot, fnet[v + u * N] - bot
            v = u
            u = prv[v]
        flow += bot
    return flow

def f(t, n, m, pairs):
    source, target = 0, 1
    A = lambda x: x * 2 + 2
    B = lambda x: x * 2 + 3
    cap = [0] * (N*N)
    for p in pairs:
        a, b = p[0]-1, p[1]-1
        cap[A(a)+N*B(b)] = INF
        cap[A(b)+N*B(a)] = INF
    for i in range(n):
        cap[source+N*A(i)] = t
        cap[B(i)+N*target] = 1
    return fordFulkerson(2 * n + 2, source, target, cap)

c = input()
for _ in range(c):
    n, t, m = map(int, raw_input().split())
    pairs = [map(int, raw_input().split()) for _ in range(m)]
    print f(t, n, m, pairs)
