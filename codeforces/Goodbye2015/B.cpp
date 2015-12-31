#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
inline int solve(ll num) {
    if (num <= 1) return 0;
    int ret = 0;
    for (int i = 2; i < 64; ++i) {
        ll val = (1ll << i) - 1 - (1ll << (i - 2));
        if (val <= num) {
            ++ret;
        }
        else return ret;
        for (int j = i - 3; j >= 0; --j) {
            val -= (1ll << j);
            val += (1ll << (j + 1));
            if (val <= num) {
                ++ret;
            }
            else return ret;
        }
    }
    return ret;
}
int main() {
    ll a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1) << endl;
    return 0;
}
