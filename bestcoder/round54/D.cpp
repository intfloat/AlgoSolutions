#include <vector>
#include <algorithm>
#include <cstdio>
#include <string.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const int MAX_N = 20005;
char s[MAX_N];
vector<int> val(MAX_N);
inline void solve() {
    scanf("%s", s);
    int sz = strlen(s);
    fill(val.begin(), val.end(), 0);
    vector<ll> h[35];
    vector<ll> sm(35, 0);
    for (int i = 1; i <= 32; ++i) {
        for (int j = 0; j + i - 1 < sz; ++j) {
            val[j] = (val[j] << 1) + (s[j + i - 1] - 'A');
            h[i].push_back(val[j]);
        }
        sort(h[i].begin(), h[i].end());
        h[i].resize(unique(h[i].begin(), h[i].end()) - h[i].begin());
        sm[i] = sm[i - 1] + ((1ll << i) - h[i].size());
    }
    int N;
    ll K;
    scanf("%d", &N);
    FOR(i, N) {
        scanf("%lld", &K);
        int pos = lower_bound(sm.begin(), sm.end(), K) - sm.begin();
        ll l = 0, r = (1ll << pos) - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll cnt = sm[pos - 1] + mid + 1ll;
            int idx = upper_bound(h[pos].begin(), h[pos].end(), mid) - h[pos].begin();
            cnt -= idx;
            if (cnt < K) l = mid + 1;
            else if (cnt > K) r = mid - 1;
            else if (idx > 0 && h[pos][idx - 1] == mid) r = mid - 1;
            else {
                string res;
                FOR(j, pos) {
                    if ((1ll << j) & mid) res = "B" + res;
                    else res = "A" + res;
                }
                printf("%s\n", res.c_str());
                break;
            }
        }
    }
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
