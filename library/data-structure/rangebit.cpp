#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N = 1005;
ll fmul[MAX_N], fadd[MAX_N];
// initialize two Fenwick trees
inline void init() {
    memset(fmul, 0, sizeof fmul);
    memset(fadd, 0, sizeof fadd);
}
// add val to pos
inline void update(ll* f, int pos, ll val) {
    if (pos == 0) return;
    while (pos < MAX_N) {
        f[pos] += val;
        pos += pos & (-pos);
    }
}
// query sum in range [1, pos] in a single Fenwick tree
inline ll query(ll* f, int pos) {
    ll sum = 0;
    while (pos > 0) {
        sum += f[pos];
        pos -= pos & (-pos);
    }
    return sum;
}
// add val to [1, pos]
inline void updateSingle(int pos, ll val) {
    if (pos == 0) return;
    update(fadd, pos, val * pos);
    update(fmul, 1, val);
    update(fmul, pos, -val);
}
// add val to [l, r]
inline void updateRange(int l, int r, ll val) {
    updateSingle(r, val);
    updateSingle(l - 1, -val);
}
inline ll querySingle(int pos) {
    return query(fadd, pos) + pos * query(fmul, pos);
}
// query sum in [left, right]
inline ll queryRange(int left, int right) {
    return querySingle(right) - querySingle(left - 1);
}
int main() {
    return 0;
}
