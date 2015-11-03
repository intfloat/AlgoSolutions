#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll MOD = (ll)(1e9 + 9);
const int MAX_N = 1000005;
vector<ll> f(MAX_N), two(MAX_N);
int main() {
    two[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        two[i] = (two[i - 1] * 2ll) % MOD;
    }
    int N;
    cin >> N;
    f[1] = f[2] = 0;
    ll res = 0;
    for (int i = 3; i <= N; ++i) {
        f[i] = (two[N - i] * (two[i - 2] - 1)) % MOD;
        f[i] = (f[i] + MOD) % MOD;
        res = (res + f[i]) % MOD;
    }
    cout << res << endl;
    return 0;
}
