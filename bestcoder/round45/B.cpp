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
int dp[1005][1005];
int arr[1005];

const int MAX_N = 1005;
int ptree[12][MAX_N];
struct Node {
    int lch, rch;
    int lp, rp;
};
Node nodes[MAX_N * 2];
int ptr = 0;
int N, Q, K, res;
void build_tree(int left, int right, int d, int root) {
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
    }
    return;
}
int query(int root, int left, int right, int d) {
    if (nodes[root].lp >= left && nodes[root].rp <= right) {
        int ret = ptree[d] + right + 1 - upper_bound(ptree[d] + left, ptree[d] + right + 1, K);
        return ret;
    }
    else {
        int mid = (nodes[root].lp + nodes[root].rp) / 2;
        if (right <= mid) return query(nodes[root].lch, left, right, d + 1);
        else if (left >= mid + 1) return query(nodes[root].rch, left, right, d + 1);
        else {
            return query(nodes[root].lch, left, mid, d + 1) + query(nodes[root].rch, mid + 1, right, d + 1);
        }
    }
}
void solve() {
    int n, q, x, y;
    scanf("%d %d", &n, &q);
    FOR(i, n) scanf("%d", arr + i);
    FOR(i, n) dp[i][i] = 0;
    build_tree(0, n - 1, 0, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            K = arr[j];
            dp[i][j] = dp[i][j - 1] + query(0, i, j - 1, 0);
        }
    }
    FOR(i, q) {
        scanf("%d %d", &x, &y);
        --x; --y;
        printf("%d\n", dp[x][y]);
    }
    return;
}
int main() {
    solve();
    return 0;
}
