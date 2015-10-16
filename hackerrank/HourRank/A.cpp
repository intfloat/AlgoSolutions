#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n, k, l;
    scanf("%d %d %d", &n, &k, &l);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    ll res = (ll)1e14;
    FOR(i, 1001) {
        int pos = 0, neg = 0;
        FOR(j, n) {
            if (arr[j] > i) pos += arr[j] - i;
            else neg += i - arr[j];
        }
        if (neg < pos) continue;
        ll cur = (ll)pos * k;
        neg -= pos;
        cur += (ll)neg * l;
        res = min(res, cur);
    }
    printf("%lld\n", res);
    return 0;
}
