#include <stdio.h>
#include <utility>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
void solve() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    vector<pair<int, pair<int, int> > > arr(Q);
    FOR(i, Q) { scanf("%d %d %d", &arr[i].second.first, &arr[i].second.second, &arr[i].first); }
    sort(arr.begin(), arr.end(), greater<pair<int, pair<int, int> > >());
    vector<ll> res(N, 1ll);
    FOR(i, Q) {
        int left = arr[i].second.first, right = arr[i].second.second;
        --left; --right;
        ll val = arr[i].first;
        ll g = res[left];
        for (int j = left + 1; j <= right; ++j) {
            if (g <= val) break;
            g = __gcd(g, res[j]);
        }
        if (g > val) {
            printf("Stupid BrotherK!\n");
            return;
        }
        for (int j = left; j <= right; ++j) {
            res[j] = (res[j] * val) / __gcd(val, res[j]);
        }
    }
    FOR(i, N - 1) printf("%lld ", res[i]);;
    printf("%lld\n", res[N - 1]);
    return;
}

int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) solve();
    return 0;
}
