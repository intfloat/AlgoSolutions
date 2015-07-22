#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n, k;
    ll res = 0;
    scanf("%lld %lld", &n, &k);
    if (n > k) {
        res = (n - k) * k;
        n = k;
    }
    ll cur = 1;
    for (; cur * cur <= k; ++cur) {
        res += k % cur;
    }
    for (int i = 1; i * i <= k; ++i) {
        ll up = min(n, k / i);
        ll low = max(cur, k / (i + 1) + 1);
        if (low > up) continue;
        res += k * (up - low + 1) - i * (up + low) * (up - low + 1) / 2;
    }
    printf("%lld\n", res);
    return 0;
}
