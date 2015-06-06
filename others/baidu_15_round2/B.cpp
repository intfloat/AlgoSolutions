#include <stdio.h>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <utility>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef pair<int, int> point;
vector<vector<point> > arr(5005, vector<point>(4));
inline int abs(int a) {
    if (a < 0) return -a;
    else return a;
}
vector<vector<int> > pp;
inline int get(int u, int v, int pu, int pv) {
    int ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret += abs(arr[u][pp[pu][i]].first - arr[v][pp[pv][i]].first);
        ret += abs(arr[u][pp[pu][i]].second - arr[v][pp[pv][i]].second);
    }
    return ret;
}

inline bool check(vector<point>& v, int pos) {
    FOR(i, 3) {
        if (v[pp[pos][i]].first > v[pp[pos][i + 1]].first) return false;
    }
    return true;
}
void preprocess() {
    pp.clear();
    vector<int> v;
    FOR(i, 4) v.push_back(i);
    pp.push_back(v);
    while (next_permutation(v.begin(), v.end())) pp.push_back(v);
    return;
}
int dp[5005][24];
bool ok[5005][24];
void solve() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        FOR(j, 4) scanf("%d %d", &arr[i][j].second, &arr[i][j].first);
    }
    FOR(i, N + 1) FOR(j, 24) dp[i][j] = INT_MAX / 2;
    FOR(j, 4) { arr[0][j].first = j + 1; arr[0][j].second = 0; }
    FOR(j, 24) ok[0][j] = (j == 0);
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) FOR(j, 24) ok[i][j] = check(arr[i], j);
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 24; ++j) {
            if (ok[i][j]) {
                FOR(k, 24) {
                    if (ok[i - 1][k]) dp[i][j] = min(dp[i][j], dp[i - 1][k] + get(i, i - 1, j, k));
                }
            }
        }
    }
    int res = INT_MAX / 2;
    FOR(i, 24) res = min(res, dp[N][i]);
    printf("%d\n", res);
    return;
}
int main() {
    int T;
    preprocess();
    scanf("%d", &T);
    FOR(tt, T) {
        printf("Case #%d:\n", tt + 1);
        solve();
    }
    return 0;
}
