#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> t(n), S(n), T(n), d(n);
    FOR(i, n) {
        scanf("%d %d %d", &t[i], &S[i], &T[i]);
        d[i] = abs(S[i] - T[i]);
    }
    vector<int> cnt(n, 0);
    FOR(i, n) for (int j = i + 1; j < n; ++j) {
        int d1 = 1, d2 = 1;
        if (S[i] > T[i]) d1 = -1;
        if (S[j] > T[j]) d2 = -1;
        int num = S[j] - S[i] + t[i] * d1 - t[j] * d2;
        int den = d1 - d2;
        int mx = min(t[i] + d[i], t[j] + d[j]);
        int mn = max(t[i], t[j]);
        if (den == 0) {
            if (num == 0 && mx >= mn) {
                ++cnt[i]; ++cnt[j];
            }
            continue;
        }
        else {
            double tm = num * 1.0 / den;
            if (tm > mn - 1e-8 && tm < mx + 1e-8) {
                ++cnt[i]; ++cnt[j];
            }
            continue;
        }
    }
    FOR(i, n) printf("%d ", cnt[i]);
    printf("\n");
    return 0;
}
