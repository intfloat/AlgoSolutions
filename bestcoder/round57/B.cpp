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
const ll MOD = 1000000007;
const int MAX_N = 100005;
ll twos[MAX_N];
inline void preprocess() {
    twos[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        twos[i] = (twos[i - 1] * 2ll) % MOD;
    }
}
#define ENTER 0
#define LEAVE 1
typedef pair<int, int> pii;
inline void solve() {
    int n, l, r;
    scanf("%d", &n);
    vector<pii> arr;
    FOR(i, n) {
        scanf("%d %d", &l, &r);
        arr.push_back(make_pair(l, ENTER));
        arr.push_back(make_pair(r, LEAVE));
    }
    sort(arr.begin(), arr.end());
    int cnt = 1;
    ll res = 0;
    for (int i = 1; i < (int)arr.size(); ++i) {
        ll len = arr[i].first - arr[i - 1].first;
        ll tmp = (twos[n] - twos[n - cnt]) % MOD;
        tmp = (tmp + MOD) % MOD;
        res = (res + tmp * len) % MOD;
        if (arr[i].second == ENTER) ++cnt;
        else --cnt;
    }
    cout << res << endl;
}
int main() {
    preprocess();
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
