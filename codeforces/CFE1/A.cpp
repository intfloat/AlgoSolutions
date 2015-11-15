#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        ll n;
        cin >> n;
        ll res = n * (n + 1) / 2ll;
        ll cur = 1;
        while (cur <= n) {
            res -= 2ll * cur;
            cur *= 2ll;
        }
        cout << res << endl;
    }
    return 0;
}
