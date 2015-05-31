#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
ll C, N, V;
void solve() {
    cin >> C >> N >> V;
    vector<ll> den(N);
    FOR(i, N) cin >> den[i];
    sort(den.begin(), den.end());
    ll cur = 0;
    vector<ll> add;
    FOR(i, den.size()) {
        while (den[i] > cur + 1) {
            add.push_back(cur + 1);
            cur += (cur + 1) * C;
        }
        cur += den[i] * C;
        if (cur >= V) break;
    }
    while (cur < V) {
        add.push_back(cur + 1);
        cur += (cur + 1) * C;
    }
    cout << add.size() << endl;
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
