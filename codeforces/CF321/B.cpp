#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, d;
    scanf("%d %d", &n, &d);
    vector<pii> factor(n + 1);
    FOR(i, n) {
        scanf("%d %d", &factor[i + 1].first, &factor[i + 1].second);
    }
    sort(factor.begin() + 1, factor.end());
    vector<ll> prefix(n + 1, 0);
    prefix[1] = factor[1].second;
    for (int i = 2; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + factor[i].second;
    }
    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        pii val = make_pair(factor[i].first + d, -1);
        int pos = upper_bound(factor.begin() + i, factor.end(), val) - factor.begin();
        ll cur = prefix[pos - 1] - prefix[i - 1];
        mx = max(mx, cur);
    }
    cout << mx << endl;
    return 0;
}
