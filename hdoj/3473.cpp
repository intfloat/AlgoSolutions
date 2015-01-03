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
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;

const int MAX_N = 10005;
const int LEVEL = 20;
ll sum[MAX_N], lsum, lacc[LEVEL][MAX_N];
int num[LEVEL][MAX_N], cnt[LEVEL][MAX_N], arr[MAX_N];

void build_tree(int left, int right, int d) {
    assert(left <= right);
    if (left == right) return;
    int mid_pos = (left + right) / 2;
    int mid_val = arr[mid_pos];
    int leq = 0;
    for (int i = left; i <= mid_pos; ++i) leq += (arr[i] == mid_val);
    int lptr = left, rptr = mid_pos + 1, dleft = 0;
    ll acc = 0;
    for (int i = left; i <= right; ++i) {
        if (num[d][i] < mid_val) {
            num[d + 1][lptr++] = num[d][i];
            ++dleft;
            acc += num[d][i];
            lacc[d][i] = acc;
            cnt[d][i] = dleft;
        }
        else if (num[d][i] == mid_val && leq > 0) {
            num[d + 1][lptr++] = num[d][i];
            ++dleft; --leq;
            acc += num[d][i];
            lacc[d][i] = acc;
            cnt[d][i] = dleft;
        }
        else {
            num[d + 1][rptr++] = num[d][i];
            cnt[d][i] = dleft;
            lacc[d][i] = acc;
        }
        // cout << d << " " << i << " " << lacc[d][i] << endl;
    }
    build_tree(left, mid_pos, d + 1);
    build_tree(mid_pos + 1, right, d + 1);
    return;
}

int query(int left, int right, int ql, int qr, int k, int d) {
    // cout << left << " " << right << " " << ql << " " << qr << " " << k << " " << d << endl;
    assert(left <= right && ql <= qr && ql >= left && qr <= right);
    if (ql == qr) { assert(k == 1); return num[d][ql]; }
    int lcnt = 0;
    if (ql != left) lcnt = cnt[d][ql - 1];
    int total = cnt[d][qr] - lcnt;
    int mid = (left + right) / 2;
    if (total >= k) {
        int nl = left + lcnt;
        int nr = left + cnt[d][qr] - 1;
        return query(left, mid, nl, nr, k, d + 1);
    }
    else {
        int nl = mid + 1 + (ql - left - lcnt);
        int nr = mid + 1 + (qr - left + 1 - cnt[d][qr]) - 1;
        if (ql != left) lsum += lacc[d][qr] - lacc[d][ql - 1];
        else lsum += lacc[d][qr];
        return query(mid + 1, right, nl, nr, k - total, d + 1);
    }
}

int main() {
    int T, N, Q, l, r;
    scanf("%d", &T);
    for (int tt = 1; tt <= T; ++tt) {
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        memset(num, 0, sizeof(num));
        printf("Case #%d:\n", tt);
        scanf("%d", &N);
        FOR(i, N) {
            scanf("%d", arr + i + 1);
            num[0][i + 1] = arr[i + 1];
            sum[i + 1] = arr[i + 1] + sum[i];
        }
        sort(arr + 1, arr + N + 1);
        build_tree(1, N, 0);
        scanf("%d", &Q);
        FOR(i, Q) {
            scanf("%d%d", &l, &r);
            ++l; ++r;
            int total = r - l + 1;
            int k = (total + 1) / 2;
            lsum = 0;
            ll median = query(1, N, l, r, k, 0);
            // add median for bottom layer
            lsum += median;
            ll res = k * median - (ll)lsum + (ll)(sum[r] - sum[l - 1] - lsum) - (total - k) * median;
            printf("%lld\n", res);
        }
        printf("\n");
    }
    return 0;
}
