#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100100;
const int MAX_M = 500100;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], dp[MAX_N], degree[MAX_N];
int n, ptr = 0;
inline void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
    pnt[ptr] = from; nt[ptr] = head[to]; head[to] = ptr++;
}
void update(int pos) {
    dp[pos] = 1;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to < pos) {
            dp[pos] = max(dp[pos], dp[to] + 1);
        }
    }
}
int main() {
    int m, u, v;
    memset(head, -1, sizeof head);
    memset(dp, -1, sizeof dp);
    memset(degree, 0, sizeof degree);
    scanf("%d %d", &n, &m);
    FOR(i, m) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
        ++degree[u];
        ++degree[v];
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) {
            update(i);
        }
        res = max(res, (ll)degree[i] * (ll)dp[i]);
    }
    cout << res << endl;
    return 0;
}
