#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cstdio>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef unsigned long long ll;
vector<ll> a, b, tmp;
int n;
inline void merge_sort(vector<ll>& arr, int idx) {
    ll number = (1ll << idx);
    if (!(arr[0] & number)) return;
    int mid;
    for (int i = 0; i < n; ++i) {
        if (!(arr[i] & number)) {
            mid = i;
            break;
        }
        else {
            arr[i] -= number;
        }
    }
    int p1 = 0, p2 = mid, ptr = 0;
    while (p1 < mid && p2 < n) {
        if (arr[p1] > arr[p2]) {
            tmp[ptr++] = arr[p1++];
        }
        else {
            tmp[ptr++] = arr[p2++];
        }
    }
    while (p1 < mid) tmp[ptr++] = arr[p1++];
    while (p2 < n) tmp[ptr++] = arr[p2++];
    FOR(i, n) arr[i] = tmp[i];
    return;
}
void solve() {
    scanf("%d", &n);
    a.resize(n); b.resize(n); tmp.resize(n);
    FOR(i, n) scanf("%lld", &a[i]);
    FOR(i, n) scanf("%lld", &b[i]);
    ll res = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<ll>());
    ll c1, c2, c3, t1, t2, t3;
    int p1, p2, p3;
    for (int i = 61; i >= 0; --i) {
        c1 = c2 = c3 = 0;
        p1 = p2 = p3 = 0;
        t1 = (1ll << i);
        t2 = (1ll << (i + 1));
        t3 = t1 + t2;
        for (int j = 0; j < n; ++j) {
            while (p1 < n && a[j] + b[p1] >= t1) ++p1;
            while (p2 < n && a[j] + b[p2] >= t2) ++p2;
            while (p3 < n && a[j] + b[p3] >= t3) ++p3;
            c1 += p1; c2 += p2; c3 += p3;
        }
        if ((c1 - c2 + c3) % 2) res += (1ll << i);
        if (i > 0) {
            reverse(a.begin(), a.end());
            merge_sort(a, i);
            reverse(a.begin(), a.end());
            merge_sort(b, i);
        }
    }
    printf("%lld\n", res);
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        solve();
    }
    return 0;
}
