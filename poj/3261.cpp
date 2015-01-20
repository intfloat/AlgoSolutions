#include <vector>
#include <list>
#include <limits.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdlib.h>
using namespace std;


const int maxn = 20005;
// auxiliary array
int wb[maxn], wv[maxn], wss[maxn];
int n, r[maxn], sa[maxn], rank[maxn], h[maxn];
// string s;

bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}

/*
 * r is an array
 * sa is an array storing result
 * n is length of r
 * m is radix
 */
void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = rank, *y = wb, *t;
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
    return;
}

void height() {
    int j, k = 0;
    for (int i = 1; i <= n; ++i) rank[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        for (k > 0? k--:0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; ++k);
        h[rank[i]] = k;
    }
    return;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    n = N;
    for (int i = 0; i < N; ++i) { scanf("%d", r + i); ++r[i]; }
    r[N] = 0;
    da(r, sa, N + 1, 50);
    height();

    // for (int i = 1; i <= N; ++i) cout << h[i] << endl;

    int left = 1, right = N;
    while (left < right) {
        int mid = (left + right) / 2;
        // avoid looping forever
        if (mid == left) mid = right;
        int cnt = 0;
        bool ok = false;
        for (int i = 1; i <= N; ++i) {
            if (cnt >= K - 1) { ok = true; break; }
            if (h[i] >= mid) ++cnt;
            else cnt = 0;
        }
        if (ok || cnt >= K - 1) left = mid;
        else right = mid - 1;
    }
    printf("%d\n", left);
    return 0;
}
