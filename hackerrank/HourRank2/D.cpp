#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef unsigned long long ll;
typedef pair<int, int> pii;
const int MAX_N = 1000005;
const int r = 29;
// MOD needs to be large to avoid collision...
const ll MOD = 1000000000000009ll;
vector<vector<int> > fac(MAX_N);
vector<ll> h(MAX_N);
void preprocess() {
    srand(time(NULL));
    vector<bool> prime(MAX_N, true);
    for (int i = 2; i < MAX_N; ++i) {
        if (prime[i]) {
            for (int j = i; j < MAX_N; j +=i) {
                int cnt = 0, val = j;
                while (val % i == 0) {
                    val /= i;
                    ++cnt;
                    fac[j].push_back(i);
                }
                prime[j] = false;
            }
        }
    }
    h[0] = 1;
    for (int i = 1; i < MAX_N; ++i) {
        h[i] = (h[i - 1] * rand()) % MOD;
    }
}
int main() {
    preprocess();
    int N, x;
    scanf("%d", &N);
    map<ll, int> mp;
    mp[0] = 1;
    ll cur = 0, res = 0;
    FOR(i, N) {
        scanf("%d", &x);
        FOR(j, fac[x].size()) {
            cur ^= h[fac[x][j]];
        }
        res += mp[cur];
        ++mp[cur];
    }
    printf("%lld\n", res);
    return 0;
}
