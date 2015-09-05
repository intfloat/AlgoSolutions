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
const int maxn = 1000005;
vector<ll> a(maxn);
inline void preprocess() {
    int i,j;
    for (i = 1; i <= maxn; ++i) a[i] = i;
    for (i = 2; i <= maxn; i += 2) a[i] /= 2;
    for (i = 3; i <= maxn; i += 2) {
        if (a[i] == i) {
            for (j = i; j <= maxn; j += i)
                a[j] = a[j] / i * (i - 1);
        }
    }
}
inline void solve() {
    int N;
    scanf("%d", &N);
    printf("%lld\n", a[N + 1]);
}
int main() {
    int T;
    preprocess();
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
