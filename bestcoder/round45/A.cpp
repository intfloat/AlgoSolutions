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
void solve() {
    ll n;
    cin >> n;
    int res = 0;
    bool zero = true;
    FOR(i, 64) {
        if (n & (1ll << i)) {
            if (zero) {
                zero = false;
                ++res;
            }
        }
        else {
            zero = true;
        }
    }
    cout << res << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        // printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
