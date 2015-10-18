#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void solve() {
    int N;
    scanf("%d", &N);
    ll mn = 0, mx = ~(1ll << 63);
    vector<ll> P(N), K(N);
    bool ok = false;
    FOR(i, N) {
        cin >> P[i] >> K[i];
        if (ok) continue;
        if (P[i] == 100 && !ok) {
            ok = true;
            mn = mx = K[i];
            continue;
        }
        K[i] = K[i] * 100;
        if (P[i] > 0) mx = min(mx, K[i] / P[i]);
        mn = max(mn, K[i] / (P[i] + 1) + 1ll);
    }
    if (mn == mx) printf("%lld\n", mn);
    else printf("-1\n");
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
