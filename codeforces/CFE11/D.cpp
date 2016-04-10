#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    scanf("%d", &n);
    vector<pii> arr(n);
    FOR(i, n) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    map<pii, int> cnt;
    FOR(i, n) {
        for (int j = i + 1; j < n; ++j) {
            ++cnt[{arr[i].first + arr[j].first, arr[i].second + arr[j].second}];
        }
    }
    ll res = 0;
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        res += (ll)(it->second) * (it->second - 1ll) / 2;
    }
    cout << res << endl;
    return 0;
}
