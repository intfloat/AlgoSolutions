#include <algorithm>
#include <stdio.h>
#include <cassert>
#include <string.h>
#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

const int MAX_N = 100005;
const int LEVEL = 20;
int arr[MAX_N];
int num[LEVEL][MAX_N], cnt[LEVEL][MAX_N];

void build_tree(int left, int right, int d) {
    // cout << left << " " << right << " " << d << endl;
    assert(left <= right);
    if (left >= right) return;
    int midpos = (left + right) / 2;
    int midval = arr[midpos];
    int leq = 0;
    for (int i = left; i <= midpos; ++i) leq += (arr[i] == midval);
    int lptr = left, rptr = midpos + 1, dleft = 0;
    for (int i = left; i <= right; ++i) {
        if (num[d][i] < midval) {
            num[d + 1][lptr++] = num[d][i];
            ++dleft;
            cnt[d][i] = dleft;
        }
        else if (num[d][i] == midval && leq > 0) {
            num[d + 1][lptr++] = num[d][i];
            --leq; ++dleft;
            cnt[d][i] = dleft;
        }
        else {
            num[d + 1][rptr++] = num[d][i];
            cnt[d][i] = dleft;
        }
    }
    assert(lptr == midpos + 1);
    build_tree(left, midpos, d + 1);
    build_tree(midpos + 1, right, d + 1);
    return;
}

int query(int left, int right, int ql, int qr, int k, int d) {
    // cout << left << " " << right << " " << ql << " " << qr << " " << k << " " << d << endl;
    assert(left <= ql && right >= qr);
    assert(left <= right);
    assert(ql <= qr);
    if (ql == qr) { return num[d][ql]; }
    int t = 0;
    if (ql > left) t = cnt[d][ql - 1];
    int lcnt = -1;
    int mid = (left + right) / 2;
    if (ql == left) lcnt = cnt[d][qr];
    else lcnt = cnt[d][qr] - t;
    // cout << "lcnt: " << lcnt << endl;
    assert(lcnt >= 0);
    // go to left subtree
    if (lcnt >= k) {
        int nl = left + t;
        int nr = left + cnt[d][qr] - 1;
        return query(left, mid, nl, nr, k, d + 1);
    }
    // go to right subtree
    else {
        int nl = mid + 1 + (ql - left - t);
        int nr = mid + 1 + (qr - left + 1 - cnt[d][qr]) - 1;
        return query(mid + 1, right, nl, nr, k - lcnt, d + 1);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, n) { scanf("%d", arr + i + 1); num[0][i + 1] = arr[i + 1]; }
    sort(arr + 1, arr + n + 1);
    memset(cnt, 0, sizeof(cnt));
    build_tree(1, n, 0);
    // cout << "here" << endl;
    int left, right, k;
    FOR(i, m) {
        scanf("%d%d%d", &left, &right, &k);
        printf("%d\n", query(1, n, left, right, k, 0));
    }
    return 0;
}
