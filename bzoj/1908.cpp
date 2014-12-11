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

const int MAX_N = 1005;
int p[MAX_N], cost[MAX_N], cnt[MAX_N];
double w[MAX_N];

int main() {
    int N, R, x, y;
    while (cin >> N >> R) {
        if (N == 0 && R == 0) break;
        --R;
        FOR(i, N) cin >> cost[i];
        int res = accumulate(cost, cost + N, 0);
        FOR(i, MAX_N) {
            p[i] = i;
            cnt[i] = 1;
            w[i] = cost[i];
        }
        FOR(i, N - 1) {
            cin >> x >> y;
            --x; --y;
            p[y] = x;
        }
        FOR(i, N - 1) {
            double mx = -1;
            int pos = -1;
            FOR(j, N) {
                if (w[j] > mx && j != R) {
                    mx = w[j];
                    pos = j;
                }
            }
            // assert(pos >= 0);
            res += cnt[p[pos]] * cost[pos];
            cnt[p[pos]] += cnt[pos];
            cost[p[pos]] += cost[pos];
            w[p[pos]] = 1.0 * cost[p[pos]] / cnt[p[pos]];
            w[pos] = -1;
            FOR(j, N) {
                if (p[j] == pos) p[j] = p[pos];
            }
        }
        cout << res << endl;
    }
    return 0;
}
