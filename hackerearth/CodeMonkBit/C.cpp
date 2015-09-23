#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
int n, m, k;
vector<int> keys;
vector<point> arr;
vector<vector<int> > ok;
inline void solve() {
    scanf("%d %d %d", &n, &m, &k);
    keys.resize(n);
    arr.resize(m);
    ok.resize(n);
    FOR(i, n) ok[i].clear();
    FOR(i, n) scanf("%d", &keys[i]);
    FOR(i, m) scanf("%d", &arr[i].second);
    FOR(i, m) scanf("%d", &arr[i].first);
    sort(arr.begin(), arr.end(), greater<point>());
    FOR(i, n) FOR(j, m) {
        if (__gcd(arr[j].second, keys[i]) > 1) {
            ok[i].push_back(j);
        }
    }
    int res = 0;
    bool visited[105];
    FOR(i, 1 << n) {
        if (__builtin_popcount(i) != k) continue;
        FOR(j, m) visited[j] = false;
        int mx = 0;
        FOR(j, n) {
            if ((1 << j) & i) {
                FOR(p, ok[j].size()) {
                    int to = ok[j][p];
                    if (!visited[to]) {
                        visited[to] = true;
                        mx += arr[to].first;
                    }
                }
            }
        }
        res = max(res, mx);
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
