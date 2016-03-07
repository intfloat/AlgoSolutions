#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[500005];
int main() {
    ll a, b, T;
    int n;
    cin >> n >> a >> b >> T;
    scanf(" %s", s);
    ll cost = (n - 1) * a + n;
    FOR(i, n) {
        if (s[i] == 'w') cost += b;
    }
    if (T >= cost) {
        cout << n << endl;
        return 0;
    }
    --T;
    if (s[0] == 'w') T -= b;
    if (T < 0) {
        printf("0\n");
        return 0;
    }
    vector<ll> l(n + 1, 0), r(n + 1, 0);
    for (int i = n - 1; i > 0; --i) {
        l[i] = l[i + 1] + a + 1;
        if (s[i] == 'w') l[i] += b;
    }
    for (int i = 1; i < n; ++i) {
        r[i] = r[i - 1] + a + 1;
        if (s[i] == 'w') r[i] += b;
    }
    int res = 1, ptr = n - 1;
    for (int i = n - 1; i > 0; --i) {
        if (T >= l[i]) res = max(res, n - i + 1);
        else break;
        ll rem = T - l[i] - a * (n - i);
        if (rem <= 0) continue;
        while (ptr >= 0 && r[ptr] > rem) --ptr;
        res = max(res, n - i + ptr + 1);
    }
    ptr = 1;
    for (int i = 1; i < n; ++i) {
        if (T >= r[i]) res = max(res, i + 1);
        else break;
        ll rem = T - r[i] - a * i;
        if (rem <= 0) continue;
        while (ptr != 0 && l[ptr] > rem) ptr = (ptr + 1) % n;
        if (ptr == 0) res = max(res, i + 1);
        else res = max(res, i + 1 + n - ptr);
    }
    printf("%d\n", res);
    return 0;
}
