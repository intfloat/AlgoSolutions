#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
const int MAX_N = 200005;
int arr[MAX_N], ptree[19][MAX_N];
struct Node {
    int lch, rch;
    int lp, rp;    
};
Node nodes[MAX_N * 2];
int ptr = 0;
int N, Q, K, res;
void build_tree(int left, int right, int d, int root) {
    assert(left <= right);
    nodes[root].lp = left; nodes[root].rp = right;
    if (left == right) {
        nodes[root].lch = nodes[root].rch = -1;     
        ptree[d][left] = arr[left];
        return;
    }
    else {
        int mid = (left + right) / 2;
        nodes[root].lch = ++ptr;
        build_tree(left, mid, d + 1, ptr);
        nodes[root].rch = ++ptr;
        build_tree(mid + 1, right, d + 1, ptr);
        int lptr = left, rptr = mid + 1, pos = left;
        while (lptr <= mid && rptr <= right) {
            if (ptree[d + 1][lptr] <= ptree[d + 1][rptr]) ptree[d][pos++] = ptree[d + 1][lptr++];
            else ptree[d][pos++] = ptree[d + 1][rptr++];
        }
        while (lptr <= mid) ptree[d][pos++] = ptree[d + 1][lptr++];
        while (rptr <= right) ptree[d][pos++] = ptree[d + 1][rptr++];
        assert(pos == right + 1);
    }
    return;
}
void query(int root, int left, int right, int d) {
    if (nodes[root].lp >= left && nodes[root].rp <= right) {
        int idx = lower_bound(ptree[d] + left, ptree[d] + right + 1, K) - ptree[d];
        if (idx == left) res = min(res, abs(ptree[d][idx] - K));
        else if (idx == right + 1) res = min(res, abs(ptree[d][right] - K));
        else {
            res = min(res, abs(ptree[d][idx] - K));
            res = min(res, abs(ptree[d][idx - 1] - K));
        }
        return;
    }
    else {
        int mid = (nodes[root].lp + nodes[root].rp) / 2;
        if (right <= mid) query(nodes[root].lch, left, right, d + 1);
        else if (left >= mid + 1) query(nodes[root].rch, left, right, d + 1);
        else {
            query(nodes[root].lch, left, mid, d + 1);
            query(nodes[root].rch, mid + 1, right, d + 1);
        }        
    }
    return;
}
void solve() {
    scanf("%d %d", &N, &Q);
    FOR(i, N) scanf("%d", arr + i);
    ptr = 0;
    build_tree(0, N - 1, 0, 0);
    int left, right;
    FOR(q, Q) {
        scanf("%d %d %d", &left, &right, &K);
        --left; --right;
        res = INT_MAX;
        query(0, left, right, 0);
        printf("%d\n", res);
    }
    return;
}
int main(){
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
