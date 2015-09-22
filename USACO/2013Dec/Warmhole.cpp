#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
int res = 0;
int x[13], y[13], match[13], nt[13], n;
bool visited[13];
int cnt[13];
inline bool check() {
    FOR(S, n) {
        memset(cnt, 0, sizeof cnt);
        int ptr = S; ++cnt[ptr];
        while (true) {
            ptr = match[ptr];
            ptr = nt[ptr];
            if (ptr < 0 || cnt[ptr]) break;
            ++cnt[ptr];
        }
        if (ptr == S) return true;
    }
    return false;
}
void dfs(int pos) {
    if (pos == n) {
        res += check();
        return;
    }
    if (visited[pos]) {
        dfs(pos + 1);
        return;
    }
    visited[pos] = true;
    for (int i = pos + 1; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            match[pos] = i;
            match[i] = pos;
            dfs(pos + 1);
            visited[i] = false;
        }
    }
    visited[pos] = false;
    return;
}
int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%d %d", &x[i], &y[i]);
    }
    FOR(i, n) {
        nt[i] = -1;
        int mn = INT_MAX;
        for (int j = 0; j < n; ++j) {
            if (y[j] == y[i] && x[j] > x[i] && x[j] < mn) {
                mn = x[j];
                nt[i] = j;
            }
        }
    }
    memset(visited, false, sizeof visited);
    dfs(0);
    printf("%d\n", res);
    return 0;
}
