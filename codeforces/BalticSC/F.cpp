#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    ll l, r;
    scanf("%d", &n);
    FOR(i, n) {
        scanf("%I64d %I64d", &l, &r);
        double res = 1.0 / (double)l - 1.0 / (r + 1.0);
        printf("%.10lf\n", res);
    }
    return 0;
}
