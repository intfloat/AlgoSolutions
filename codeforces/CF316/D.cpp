#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 500005;
vector<int> in(MAX_N), out(MAX_N), dep(MAX_N);
vector<int> status[MAX_N];
vector<int> it[MAX_N], ot[MAX_N];
int head[MAX_N], nt[MAX_N], pnt[MAX_N], ptr, cnt;
char s[MAX_N];
inline void addedge(int from, int to) {
    pnt[ptr] = to; nt[ptr] = head[from]; head[from] = ptr++;
}
void dfs(int pos, int d) {
    dep[pos] = d;
    in[pos] = cnt++;
    it[d].push_back(in[pos]);
    for (int i = head[pos]; i != -1; i = nt[i]) {
        dfs(pnt[i], d + 1);
    }
    out[pos] = cnt++;
    ot[d].push_back(out[pos]);
    int val = 0;
    if (!status[d].empty()) {
        val = status[d].back();
    }
    status[d].push_back(val ^ (1 << (s[pos] - 'a')));
}
int main() {
    int n, m, v, h, fa;
    scanf("%d %d", &n, &m);
    memset(head, -1, sizeof head);
    ptr = cnt = 0;
    FOR(i, n - 1) {
        scanf("%d", &fa);
        addedge(fa, i + 2);
    }
    scanf("%s", s + 1);
    dfs(1, 1);
    FOR(i, m) {
        scanf("%d %d", &v, &h);
        if (h <= dep[v] || it[h].empty()) {
            printf("Yes\n");
            continue;
        }
        int x1 = upper_bound(it[h].begin(), it[h].end(), in[v]) - it[h].begin();
        int x2 = upper_bound(ot[h].begin(), ot[h].end(), out[v]) - ot[h].begin() - 1;
        if (x1 > x2) {
            printf("Yes\n");
            continue;
        }
        if (x1 == 0 && __builtin_popcount(status[h][x2]) <= 1) {
            printf("Yes\n");
        }
        else if (x1 > 0 && __builtin_popcount(status[h][x2] ^ status[h][x1 - 1]) <= 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
