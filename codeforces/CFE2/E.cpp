#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 100005;
const int MAX_M = MAX_N * 2;
int head[MAX_N], pnt[MAX_M], nt[MAX_M], ptr = 0, color[MAX_N], cnt[MAX_N];
map<int, int>* mp[MAX_N];
ll sm[MAX_N];
inline void addedge(int u, int v) {
    pnt[ptr] = v; nt[ptr] = head[u]; head[u] = ptr++;
    pnt[ptr] = u; nt[ptr] = head[v]; head[v] = ptr++;
}
void dfs(int pos, int fa) {
    int mx = -1, idx = -1;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == fa) continue;
        dfs(to, pos);
        if ((int)(mp[to]->size()) > mx) {
            mx = mp[to]->size();
            idx = to;
        }
    }
    if (idx == -1) {
        mp[pos] = new map<int, int>();
        (*mp[pos])[color[pos]] = 1;
        sm[pos] = color[pos];
        cnt[pos] = 1;
        return;
    }
    mp[pos] = mp[idx];
    sm[pos] = sm[idx];
    cnt[pos] = cnt[idx];
    map<int, int>& cmp = *mp[pos];
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == fa || to == idx) continue;
        for (auto it = mp[to]->begin(); it != mp[to]->end(); ++it) {
            int col = it->first, cc = it->second;
            cmp[col] += cc;
            if (cmp[col] > cnt[pos]) {
                cnt[pos] = cmp[col];
                sm[pos] = col;
            }
            else if (cmp[col] == cnt[pos]) {
                sm[pos] += col;
            }
        }
    }
    int col = color[pos], cc = 1;
    cmp[col] += cc;
    if (cmp[col] > cnt[pos]) {
        cnt[pos] = cmp[col];
        sm[pos] = col;
    }
    else if (cmp[col] == cnt[pos]) {
        sm[pos] += col;
    }
}
int main() {
    int n, u, v;
    memset(head, -1, sizeof head);
    memset(cnt, 0, sizeof cnt);
    memset(sm, 0, sizeof sm);
    scanf("%d", &n);
    FOR(i, n) scanf("%d", &color[i + 1]);
    FOR(i, n - 1) {
        scanf("%d %d", &u, &v);
        addedge(u, v);
    }
    dfs(1, -1);
    FOR(i, n) {
        printf("%I64d ", sm[i + 1]);
    }
    printf("\n");
    return 0;
}
