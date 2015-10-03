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
inline void solve() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    FOR(i, n) scanf("%d", &a[i + 1]);
    FOR(i, n) scanf("%d", &b[i + 1]);
    for (int i = 1; i <= n; ++i) {
        c[a[i]] = b[i];
    }
    vector<bool> visited(n + 1, false);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        int ptr = i, cnt = 1;
        while (!visited[c[ptr]]) {
            ptr = c[ptr];
            visited[ptr] = true;
            ++cnt;
        }
        res += max(cnt - 1, 1);
    }
    printf("%d\n", res);
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
