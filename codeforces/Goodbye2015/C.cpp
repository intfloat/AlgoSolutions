#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 505;
char g[MAX_N][MAX_N];
int rg[MAX_N][MAX_N], cg[MAX_N][MAX_N];
int main() {
    int row, col;
    scanf("%d %d", &row, &col);
    FOR(i, row) {
        scanf("%s", g[i]);
    }
    FOR(i, row) {
        rg[i][0] = 0;
        for (int j = 1; j < col; ++j) {
            if (g[i][j] == '#' || g[i][j - 1] == '#') rg[i][j] = rg[i][j - 1];
            else rg[i][j] = rg[i][j - 1] + 1;
        }
    }
    FOR(j, col) {
        cg[0][j] = 0;
        for (int i = 1; i < row; ++i) {
            if (g[i][j] == '#' || g[i - 1][j] == '#') cg[i][j] = cg[i - 1][j];
            else cg[i][j] = cg[i - 1][j] + 1;
        }
    }
    int q, res, r1, r2, c1, c2;
    scanf("%d", &q);
    FOR(tt, q) {
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        --r1; --r2; --c1; --c2;
        res = 0;
        for (int i = r1; i <= r2; ++i) {
            res += rg[i][c2];
            if (c1 > 0) {
                res -= rg[i][c1 - 1];
                res -= (g[i][c1 - 1] == g[i][c1] && g[i][c1] == '.');
            }
        }
        for (int j = c1; j <= c2; ++j) {
            res += cg[r2][j];
            if (r1 > 0) {
                res -= cg[r1 - 1][j];
                res -= (g[r1][j] == g[r1 - 1][j] && g[r1][j] == '.');
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
