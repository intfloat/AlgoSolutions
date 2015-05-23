#include <stdio.h>
#include <vector>
#include <iostream>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 1000005;
const ll MOD = 1000000007ll;
int main() {
    int T, N;
    scanf("%d", &T);
    vector<ll> res(MAX_N);
    res[1] = 1; res[2] = 2;
    for (ll i = 3; i < MAX_N; ++i) {
        res[i] = res[i - 1] + (i - 1) * res[i - 2];
        res[i] %= MOD;
    }
    FOR(tt, T) {
        scanf("%d", &N);
        cout << "Case #" << tt + 1 << ":" << endl;
        cout << res[N] << endl;
    }
    return 0;
}
