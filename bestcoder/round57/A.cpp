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
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 100105;
typedef int E;
E f[MAX_N][2];
int N[2];
void update(int k, int pos, E val){
    if (pos == 0) return;
    while (pos <= N[k]) {
        f[pos][k] += val;
        pos += pos & (-pos);
    }
}
E query(int k, int pos) {
    E ret = 0;
    while (pos > 0) {
        ret += f[pos][k];
        pos -= pos & (-pos);
    }
    return ret;
}
inline void solve() {
    int row, col, K, Q, r, c, x1, y1, x2, y2;
    scanf("%d %d %d %d", &row, &col, &K, &Q);
    N[0] = row + 5; N[1] = col + 5;
    FOR(i, N[0] + 1) f[i][0] = 0;
    FOR(i, N[1] + 1) f[i][1] = 0;
    set<int> rs, cs;
    FOR(i, K) {
        scanf("%d %d", &r, &c);
        rs.insert(r);
        cs.insert(c);
    }
    set<int>::iterator it;
    for (it = rs.begin(); it != rs.end(); ++it) update(0, *it, 1);
    for (it = cs.begin(); it != cs.end(); ++it) update(1, *it, 1);
    FOR(i, Q) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int res1 = query(0, x2) - query(0, x1 - 1);
        if (res1 == x2 - x1 + 1) {
            printf("Yes\n");
            continue;
        }
        else {
            res1 = query(1, y2) - query(1, y1 - 1);
            if (res1 == y2 - y1 + 1) {
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");
    }
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
