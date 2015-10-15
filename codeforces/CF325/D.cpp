#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef pair<int, int> pii;
const string x[] = {"LM", "LW", "MW"};
int cost[30][3], up;
map<pii, pii> dp[30];
void dfs(int pos, int A, int B, int C, int path) {
    if (pos == up + 1) {
        pii cur = make_pair(B - A, C - A);
        pii val = make_pair(A, path);
        auto it = dp[up].find(cur);
        if (it == dp[up].end() || (it->second) < val) {
            dp[up][cur] = val;
        }
        return;
    }
    dfs(pos + 1, A + cost[pos][0], B + cost[pos][1], C, (path << 2) | 0);
    dfs(pos + 1, A + cost[pos][0], B, C + cost[pos][2], (path << 2) | 1);
    dfs(pos + 1, A, B + cost[pos][1], C + cost[pos][2], (path << 2) | 2);
}
int main() {
    int n, L, M, W, p1, p2;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d %d %d", &L, &M, &W);
        cost[i][0] = L;
        cost[i][1] = M;
        cost[i][2] = W;
    }
    if (n == 1) {
        if (L == 0 && M == 0) {
            printf("LM\n");
        }
        else if (L == 0 && W == 0) {
            printf("LW\n");
        }
        else if (W == 0 && M == 0) {
            printf("MW\n");
        }
        else printf("Impossible\n");
        return 0;
    }
    up = n / 2 - 1;
    dfs(0, 0, 0, 0, 0);
    up = n - 1;
    dfs(n / 2, 0, 0, 0, 0);
    int mx = INT_MIN;
    for (auto it = dp[n / 2 - 1].begin(); it != dp[n / 2 - 1].end(); ++it) {
        pii cur = it->first;
        cur.first = -cur.first; cur.second = -cur.second;
        auto ptr = dp[n - 1].find(cur);
        if (ptr != dp[n - 1].end()) {
            int vv = (ptr->second).first + (it->second).first;
            if (vv > mx) {
                mx = vv;
                p1 = (it->second).second;
                p2 = (ptr->second).second;
            }
        }
    }
    if (mx == INT_MIN) printf("Impossible\n");
    else {
        vector<int> res(n);
        for (int i = n / 2 - 1; i >= 0; --i) {
            res[i] = (p1 & 3);
            p1 >>= 2;
        }
        for (int i = n - 1; i >= n / 2; --i) {
            res[i] = (p2 & 3);
            p2 >>= 2;
        }
        for (int i = 0; i < n; ++i) {
            printf("%s\n", x[res[i]].c_str());
        }
    }
    return 0;
}
