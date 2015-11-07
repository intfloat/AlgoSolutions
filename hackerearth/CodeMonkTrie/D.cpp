#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
const int maxn = 1000005;
char s[maxn];
// auxiliary array
int wb[maxn], wv[maxn], wss[maxn];
int n, r[maxn], sa[maxn], _rank[maxn], h[maxn];
bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
/*
 * r is an array
 * sa is an array storing result
 * n is length of r
 * m is radix
 */
inline void da(int *r, int *sa, int nn, int m) {
    int i, j, p, *x = _rank, *y = wb, *t;
    for (i = 0; i < m; ++i) wss[i] = 0;
    for (i = 0; i < nn; ++i) wss[x[i] = r[i]]++;
    for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
    for (i = nn - 1; i >= 0; --i)
       sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p < nn; j *= 2, m = p) {
        for (p = 0, i = nn - j; i < nn; ++i) y[p++] = i;
        for (i = 0; i < nn; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < nn; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wss[i] = 0;
        for (i = 0; i < nn; ++i) wss[wv[i]]++;
        for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
        for (i = nn - 1; i >= 0; --i) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < nn; ++i)
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1 : p++;
    }
}
inline void height() {
    int j, k = 0;
    for (int i = 1; i <= n; ++i) _rank[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        for (k > 0? k--:0, j = sa[_rank[i] - 1]; r[i + k] == r[j + k]; ++k);
        h[_rank[i]] = k;
    }
}
int rmq[maxn][21];
inline void rmq_init() {
    for (int i = 1; i <= n; ++i) {
        rmq[i][0] = h[i];
    }
    for (int p = 1; (1 << p) <= n; ++p) {
        for (int i = 1; i + (1 << p) <= n + 1; ++i)
            rmq[i][p] = min(rmq[i][p - 1], rmq[i + (1 << (p - 1))][p - 1]);
    }
}
// longest common prefix
inline int lcp(int x, int y) {
    int rx = _rank[x];
    int ry = _rank[y];
    if (rx > ry) swap(rx, ry);
    ++rx;
    int pw = 0;
    while ((1 << (pw + 1)) < (ry - rx + 1)) ++pw;
    int res = min(rmq[rx][pw], rmq[ry - (1 << pw) + 1][pw]);
    return res;
}

int main() {
    int N, K;
    scanf("%d %d", &K, &N);
    scanf("%s", s);
    if (K == 1) {
        printf("%d\n", N);
        return 0;
    }
    n = N;
    for (int i = 0; i < n; ++i) r[i] = s[i] - 'a' + 1;
    r[n] = 0;
    da(r, sa, n + 1, 27);
    height();
    rmq_init();
    int res = 0;
    for (int i = 1; i + K - 1 <= n; ++i) {
        int l = sa[i], r = sa[i + K - 1];
        res = max(res, lcp(l, r));
    }
    printf("%d\n", res);
    return 0;
}
