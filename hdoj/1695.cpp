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

const int MAX_N = 100005;
long long euler[MAX_N];
vector<int> prime[MAX_N];
int T, a, b, c, d, k;
void solve() {
    FOR(i, MAX_N) euler[i] = i;
    // euler[1] = 1;
    for (int i = 2; i < MAX_N; ++i) {
        if (euler[i] == i) {
            euler[i] = i - 1;
            for (int j = i * 2; j < MAX_N; j += i) {
                euler[j] = euler[j] * (i - 1) / i;
                prime[j].push_back(i);
            }
        }
        euler[i] += euler[i - 1];
    }
    return;
}

long long dfs(int pos, int d, int number) {
    long long ret = 0ll;
    for (int i = pos; i < prime[number].size(); ++i) {
        // inclusion-exclusion principle
        ret += d / prime[number][i] - dfs(i + 1, d / prime[number][i], number);
    }
    return ret;
}

int main() {
    cin >> T;
    solve();
    FOR(tt, T) {
        cin >> a >> b >> c >> d >> k;
        cout << "Case " << tt + 1 << ": ";
        if (k == 0) { cout << 0 << endl; continue; }
        b /= k; d /= k;
        if (b < d) swap(b, d);
        long long res = euler[d];
        for (int i = d + 1; i <= b; ++i)
            res += d - dfs(0, d, i);
        cout << res << endl;
    }
    return 0;
}
