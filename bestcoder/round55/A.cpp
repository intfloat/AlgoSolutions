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
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> h(n), w(n), v(n);
    double vol = 0;
    FOR(i, n) scanf("%d", &h[i]);
    FOR(i, n) {
        scanf("%d", &w[i]);
        v[i] = h[i] * (w[i] * w[i]);
        vol += v[i];
    }
    double l = 0, r = *max_element(h.begin(), h.end());
    int cnt = 0;
    while (fabs(r - l) > 1e-6 && cnt++ < 500) {
        double mid = (r + l) / 2;
        double cur = 0;
        FOR(i, n) {
            if (mid < h[i]) {
                double ratio = (h[i] - mid) / h[i];
                cur += v[i] * ratio * ratio * ratio;
            }
        }
        cur *= 2;
        if (cur < vol) r = mid;
        else l = mid;
    }
    printf("%d\n", (int)l);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
