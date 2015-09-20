#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
void solve() {
    int np, ne, nt;
    scanf("%d %d %d", &np, &ne, &nt);
    vector<ll> gp(np), ge(ne), gt(nt);
    FOR(i, np) scanf("%lld", &gp[i]);
    FOR(i, ne) scanf("%lld", &ge[i]);
    FOR(i, nt) scanf("%lld", &gt[i]);
    set<pll> extra;
    FOR(i, ne) for (int j = i + 1; j < ne; ++j) {
        ll g = __gcd(ge[i], ge[j]);
        ll a = ge[i] / g, b = ge[j] / g;
        extra.insert(make_pair(a, b));
        extra.insert(make_pair(b, a));
    }
    set<pll> base;
    FOR(i, np) FOR(j, nt) {
        ll g = __gcd(gp[i], gt[j]);
        ll a = gp[i] / g, b = gt[j] / g;
        base.insert(make_pair(a, b));
    }
    int M;
    ll P, Q;
    scanf("%d", &M);
    set<pll>::iterator it;
    FOR(i, M) {
        bool ok = false;
        scanf("%lld %lld", &P, &Q);
        for (it = extra.begin(); it != extra.end(); ++it) {
            ll a = P * ((*it).first), b = Q * ((*it).second);
            ll g = __gcd(a, b);
            a /= g;
            b /= g;
            if (base.find(make_pair(a, b)) != base.end()) {
                ok = true;
                break;
            }
        }
        if (ok) printf("Yes\n");
        else printf("No\n");
    }
    return;
}
int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ":" << endl;
        solve();
    }
    return 0;
}
