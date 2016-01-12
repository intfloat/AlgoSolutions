#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 305;
const int INF = INT_MAX / 2;
int dp[MAX_N][MAX_N];

const int maxn = 110000;
// auxiliary array
int wb[maxn], wv[maxn], wss[maxn];
int n, r[maxn], sa[maxn], _rank[maxn], h[maxn];
string s;
bool cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
/*
 * r is an array
 * sa is an array storing result
 * n is length of r
 * m is radix
 */
inline void da(int *r, int *sa, int n, int m) {
    int i, j, p, *x = _rank, *y = wb, *t;
    for (i = 0; i < m; ++i) wss[i] = 0;
    for (i = 0; i < n; ++i) wss[x[i] = r[i]]++;
    for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
    for (i = n - 1; i >= 0; --i)
       sa[--wss[x[i]]] = i;
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; ++i) y[p++] = i;
        for (i = 0; i < n; ++i) if(sa[i] >= j) y[p++] = sa[i] - j;
        for (i = 0; i < n; ++i) wv[i] = x[y[i]];
        for (i = 0; i < m; ++i) wss[i] = 0;
        for (i = 0; i < n; ++i) wss[wv[i]]++;
        for (i = 1; i < m; ++i) wss[i] += wss[i - 1];
        for (i = n - 1; i >= 0; --i) sa[--wss[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; ++i)
        x[sa[i]] = cmp(y, sa[i - 1], sa[i], j)? p - 1 : p++;
    }
}
inline void height() {
    int j, k = 0;
    for (int i = 1; i <= n; ++i) _rank[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        for (k > 0? k--:0, j = sa[_rank[i] - 1]; r[i + k] == r[j + k]; ++k);
        h[_rank[i]] = k;
    }
}
int rmq[maxn][18];
inline void rmq_init() {
    for (int i = 1; i <= n; ++i) rmq[i][0] = h[i];
    for (int p = 1; (1 << p) <= n; ++p) {
        for (int i = 1; i + (1 << p) <= n + 1; ++i)
            rmq[i][p] = min(rmq[i][p - 1], rmq[i + (1 << (p - 1))][p - 1]);
    }
}
// longest common prefix
inline int lcp(int x, int y) {
    int rx = _rank[x];
    int ry = _rank[y];
    if (rx > ry) swap(rx, ry);
    ++rx;
    int pw = 0;
    while ((1 << (pw + 1)) < (ry - rx + 1)) ++pw;
    int res = min(rmq[rx][pw], rmq[ry - (1 << pw) + 1][pw]);
    return res;
}

// inline int lcp(string& a, string& b) {
//     int up = min(a.size(), b.size());
//     FOR(i, up) {
//         if (a[i] != b[i]) return i;
//     }
//     return up;
// }
inline void solve() {
    int N, K;
    cin >> N >> K;
    vector<string> arr(N + 1);
    arr[0] = "";
    FOR(i, N) {
        cin >> arr[i + 1];
    }
    sort(arr.begin() + 1, arr.end());
    vector<int> pos(N + 1);
    s = "";
    char c = 'z' + 1;
    for (int i = 1; i <= N; ++i) {
        pos[i] = s.size();
        s += arr[i];
        s.push_back(c);
    }
    n = s.size();
    for (int i = 0; i < n; ++i) r[i] = s[i] - 'a' + 1;
    r[n] = 0;
    da(r, sa, n + 1, 28);
    height();
    rmq_init();

    FOR(i, N + 1) FOR(j, K + 1) dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            for (int p = i - 1; p >= j - 1; --p) {
                int tmp = 0;
                if (i > 0 && p > 0) tmp = lcp(pos[i], pos[p]);
                tmp = arr[p].size() - tmp + arr[i].size() - tmp;
                dp[i][j] = min(dp[i][j], dp[p][j - 1] + tmp);
            }
        }
    }
    int res = INF;
    for (int i = K; i <= N; ++i) {
        res = min(res, K + dp[i][K] + (int)arr[i].size());
    }
    cout << res << endl;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
