#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    vector<int> arr(n);
    FOR(i, n) scanf("%d", &arr[i]);
    ll res = 0;
    map<int, ll> cnt, total;
    FOR(i, n) {
        if (arr[i] % k == 0 && ((arr[i] / k) % k) == 0) {
            int n1 = arr[i] / k;
            res += total[n1];
        }
        if (arr[i] % k == 0) {
            total[arr[i]] += cnt[arr[i] / k];
        }
        ++cnt[arr[i]];
    }
    cout << res << endl;
    return 0;
}
