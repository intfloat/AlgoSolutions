// by xyz111
#include <cstdio>
#include <map>
using namespace std;

int T, len, ans, till[210000], go[210000], Next[210000], fa[210000], n1[210000], used[210000], color[210000], m, k, x, y, n;
map <int, int> mm[110000];

void add(int x, int y) {
    Next[++len] = till[x];
    till[x] = len;
    go[len] = y;
}

void bfs() {
    int q, h, i;
    for (i = 1; i <= n; i++)
        used[i] = false;
    for (n1[q = h = 1] = 1, used[1] = true; q <= h; q++)
        for (i = till[n1[q]]; i; i = Next[i]) {
            if (!used[go[i]]) {
                fa[go[i]] = n1[q];
                n1[++h] = go[i];
                used[go[i]] = true;
            }
        }
}

int main() {
    scanf("%d", &T);
    for (int mm1 = 1; mm1 <= T; mm1++) {
        scanf("%d", &n);
        len = 0;
        for (int i = 1; i <= n; i++)
            till[i] = 0, color[i] = 0;
        ans = n - 1;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            add(x, y);
            add(y, x);
        }
        printf("Case #%d:\n", mm1);
        bfs();
        for (int i = 1; i <= n; i++)
            mm[i].clear();
        for (int i = 2; i <= n; i++)
            mm[fa[i]][color[i]]++;
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &k);
            if (k == 1) printf("%d\n", n - ans);
            else {
                scanf("%d%d", &x, &y);
                ans -= mm[x][color[x]];
                ans += mm[x][y];
                if (x != 1) {
                    if (color[x] == color[fa[x]]) ans--;
                    if (y == color[fa[x]]) ans++;
                    mm[fa[x]][color[x]]--;
                    mm[fa[x]][y]++;
                }
                color[x] = y;
            }
        }
    }
}
