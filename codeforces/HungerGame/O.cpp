#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
const int MAX_N = 60005;
const int MAX_M = 1600005;
vector<int> head(MAX_N), pnt(MAX_M), nt(MAX_M), wei(MAX_M);
int ptr;
inline void addedge(int x, int y, int w) {
    pnt[ptr] = y; nt[ptr] = head[x]; wei[ptr] = w; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; wei[ptr] = w; head[y] = ptr++;
}
int main() {
    ptr = 0;
    fill(head.begin(), head.end(), -1);
    int n, m, T, K, x, y, w;
    scanf("%d %d %d %d", &n, &m, &T, &K);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d", &x, &y, &w);
        --x; --y;
        addedge(x, y, w);
    }
    vector<vector<bool> > dp(MAX_N, vector<bool>(max(100, K) + 5, false));
    vector<bool> safe(MAX_N, true);
    int res = 0, pos;
    for (int i = 0; i < T; ++i) {
        scanf("%d", &pos);
        if (res == n) {
            printf("0\n");
            continue;
        }
        --pos;
        if (dp[pos][0]) {
            printf("%d\n", n - res);
            continue;
        }
        queue<point> q;
        dp[pos][0] = true;
        if (safe[pos]) {
            ++res;
            safe[pos] = false;
        }
        q.push(make_pair(pos, 0));
        while (!q.empty()) {
            point tp = q.front(); q.pop();
            for (int j = head[tp.first]; j != -1; j = nt[j]) {
                int to = pnt[j];
                int val = tp.second + wei[j];
                if (val >= K) continue;
                if (dp[to][val]) continue;
                dp[to][val] = true;
                if (safe[to]) {
                    ++res;
                    safe[to] = false;
                }
                q.push(make_pair(to, val));
            }
        }
        printf("%d\n", n - res);
    }
    return 0;
}
