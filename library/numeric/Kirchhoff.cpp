#include <bits/stdc++.h>
using namespace std;
const int N = 15;
typedef long long ll;
int degree[N];
ll C[N][N];
ll det(ll a[N][N], int n) {
    ll ret = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (a[j][i]) {
                ll t = a[i][i] / a[j][i];
                for (int k = i; k < n; ++k)
                    a[i][k] = (a[i][k] - a[j][k] * t);
                for (int k = i; k < n; ++k)
                    swap(a[i][k], a[j][k]);
                ret = -ret;
            }
        }
        if (a[i][i] == 0) return 0;
        ret = ret * a[i][i];
    }
    if (ret < 0) ret = -ret;
    return ret;
}
int main() {
    int tcase;
    scanf("%d", &tcase);
    while (tcase--) {
        memset(degree, 0, sizeof degree);
        memset(C, 0, sizeof C);
        int n, m;
        scanf("%d %d", &n, &m);
        int u, v;
        while (m--) {
            scanf("%d %d", &u, &v);
            --u; --v;
            C[u][v] = C[v][u] = -1;
            ++degree[u]; ++degree[v];
        }
        for (int i = 0; i < n; ++i) C[i][i] = degree[i];
        printf("%lld\n", det(C, n));
    }
    return 0;
}
