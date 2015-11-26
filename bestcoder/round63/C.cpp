#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N = 1005;
int g[MAX_N][MAX_N];
double p[MAX_N][MAX_N];
double col[MAX_N];
int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &g[i][j]);
            }
        }
        for (int i = 0; i < m; ++i) col[i] = 0;
        for (int i = 0; i < n; ++i) {
            int tot = accumulate(g[i], g[i] + m, 0);
            for (int j = 0; j < m; ++j) {
                p[i][j] = 1.0 * g[i][j] / tot;
                col[j] += p[i][j];
            }
        }
        double res = 0;
        for (int i = 0; i < n; ++i) {
            res += 1;
            for (int j = 0; j < m; ++j) {
                res += p[i][j] * (col[j] - p[i][j]);
            }
        }
        printf("%.2lf\n", res);
    }
    return 0;
}
