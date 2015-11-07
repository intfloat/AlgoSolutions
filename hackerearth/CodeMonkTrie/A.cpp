#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
const int maxn = 2000005;
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
inline void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = _rank, *y = wb, *t;
    for (i = 0; i < m; ++i) wss[i] = 0;
    for (i = 0; i < n; ++i) wss[x[i] = r[i]]++;
    for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; --i)
       sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wss[i] = 0;
        for (i = 0; i < n; ++i) wss[wv[i]]++;
        for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
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
int rmq[maxn][22];
inline void rmq_init() {
    for (int i = 1; i <= n; ++i) rmq[i][0] = i - 1;
    for (int p = 1; (1 << p) <= n; ++p) {
        for (int i = 1; i + (1 << p) <= n; ++i) {
            int u = rmq[i][p - 1], v = rmq[i + (1 << (p - 1))][p - 1];
            if (_rank[u] <= _rank[v]) rmq[i][p] = u;
            else rmq[i][p] = v;
        }
    }
}
inline int query(int left, int right) {
    int k = 0;
    int length = right - left + 1;
    while ((1 << (k + 1)) < length) ++k;
    int u = rmq[left][k], v = rmq[right - (1 << k) + 1][k];
    if (_rank[u] <= _rank[v]) return u;
    else return v;
}
int main() {
    int N, Q, K;
    scanf("%d", &N);
    scanf("%s", s);
    for (int i = 0; i < N; ++i) {
        s[i + N] = s[i];
    }
    s[N + N] = '\0';
    n = 2 * N;
    for (int i = 0; i < n; ++i) r[i] = s[i] - 'a' + 1;
    r[n] = 0;
    da(r, sa, n + 1, 27);
    height();
    rmq_init();
    scanf("%d", &Q);
    FOR(i, Q) {
        scanf("%d", &K);
        printf("%d\n", query(1, K + 1));
    }
    return 0;
}
