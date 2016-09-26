#include <bits/stdc++.h>
using namespace std;

ll MOD = (ll)(1e9 + 7), base = 29;
int msearch(const string& s1, const string& s2) {
    if (s1.size() < s2.size() || s2.empty()) {
        return -1;
    }
    ll h1 = 0, h2 = 0;
    FOR(i, s2.size()) {
        h2 = (h2 * base + (s2[i] - 'a')) % MOD;
        h1 = (h1 * base + (s1[i] - 'a')) % MOD;
    }
    ll pw = 1;
    FOR(i, s2.size() - 1) {
        pw = (pw * base) % MOD;
    }
    for (int i = (int)s2.size(); i <= (int)s1.size(); ++i) {
        if (h1 == h2) {
            int ans = i - s2.size();
            return ans;
        }
        if (i == (int)s1.size()) return -1;
        else {
            h1 -= pw * (s1[i - s2.size()] - 'a');
            h1 %= MOD;
            h1 = (h1 + MOD) % MOD;

            h1 = (h1 * base + s1[i] - 'a') % MOD;
        }
    }
    return -1;
}

int main() {
    return 0;
}
