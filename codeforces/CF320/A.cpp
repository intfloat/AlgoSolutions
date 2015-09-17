#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    ll a, b;
    cin >> a >> b;
    if (a < b) {
        printf("-1\n");
        return 0;
    }
    ll n = (a - b) / (2 * b);
    double res;
    if (n == 0) res = (a + b) / (2.0 * n + 2.0);
    else res = min((a - b) / (2.0 * n), (a + b) / (2.0 * n + 2.0));
    if (res <= 1e-9) printf("-1\n");
    else printf("%.10lf\n", res);
    return 0;
}
