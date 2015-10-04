#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n), g(n);
    FOR(i, n) scanf("%d", &arr[i]);
    for (int i = 1; i < n; ++i) {
        g[i] = __gcd(i, n);
    }
    ll res = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i) continue;
        vector<int> mx(i, 0);
        FOR(j, n) mx[j % i] = max(mx[j % i], arr[j]);
        int l = 0, r = 0;
        while (l < (int)arr.size()) {
            if (arr[l] != mx[l % i]) { ++l; continue; }
            r = l;
            while (arr[r] == mx[r % i]) {
                r = (r + 1) % n;
                if (r == l) break;
            }
            int len = (r + n - l) % n;
            if (len == 0) len = n;
            for (int j = i; j <= len && j < n; j += i) {
                if (g[j] != i) continue;
                if (len == n) { res += n; continue; }
                res += (len - j + 1);
                if (r <= l && r >= j) res -= (r - j + 1);
            }
            if (r <= l) break;
            else l = r;
        }
    }
    cout << res << endl;
    return 0;
}
