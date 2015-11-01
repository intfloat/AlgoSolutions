#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 150000;
const int MAX_M = MAX_N * 2;
int head[MAX_N], nt[MAX_M], pnt[MAX_M], ptr = 0;
bool attack[MAX_N];
int mx[MAX_N], tot[MAX_N];
vector<int> len[MAX_N];
inline void addedge(int x, int y) {
    pnt[ptr] = y; nt[ptr] = head[x]; head[x] = ptr++;
    pnt[ptr] = x; nt[ptr] = head[y]; head[y] = ptr++;
}
void dfs1(int pos, int f) {
    int cur = 0;
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == f) continue;
        dfs1(to, pos);
        if (tot[to] >= 0) {
            cur += 2 + tot[to];
            len[pos].push_back(1 + mx[to]);
            mx[pos] = max(mx[pos], 1 + mx[to]);
        }
    }
    if (attack[pos]) len[pos].push_back(0);
    sort(len[pos].begin(), len[pos].end(), greater<int>());
    if (attack[pos] || cur > 0) {
        tot[pos] = cur;
        mx[pos] = max(mx[pos], 0);
    }
}
void dfs2(int pos, int f) {
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == f) continue;
        int val = tot[pos];
        if (tot[to] >= 0) val -= 2 + tot[to];
        if (mx[to] >= 0 && len[pos][0] == mx[to] + 1) {
            if (len[pos].size() <= 1) continue;
            mx[to] = max(mx[to], len[pos][1] + 1);
            len[to].push_back(len[pos][1] + 1);
            tot[to] += 2 + val;
            sort(len[to].begin(), len[to].end(), greater<int>());
        }
        else if (len[pos].size() > 0) {
            mx[to] = max(mx[to], len[pos][0] + 1);
            len[to].push_back(len[pos][0] + 1);
            tot[to] += 2 + val;
            sort(len[to].begin(), len[to].end(), greater<int>());
        }
    }
    for (int i = head[pos]; i != -1; i = nt[i]) {
        int to = pnt[i];
        if (to == f) continue;
        dfs2(to, pos);
    }
}
int main() {
    int n, m, x, y;
    memset(head, -1, sizeof head);
    memset(attack, false, sizeof attack);
    memset(tot, -1, sizeof tot);
    memset(mx, -1, sizeof mx);
    scanf("%d %d", &n, &m);
    FOR(i, n - 1) {
        scanf("%d %d", &x, &y);
        addedge(x, y);
    }
    FOR(i, m) {
        scanf("%d", &x);
        attack[x] = true;
    }
    dfs1(1, -1);
    dfs2(1, -1);
    int res = INT_MAX, idx = -1;
    for (int i = 1; i <= n; ++i) {
        if (attack[i] && tot[i] - mx[i] < res) {
            res = tot[i] - mx[i];
            idx = i;
        }
    }
    printf("%d\n", idx);
    printf("%d\n", res);
    return 0;
}
