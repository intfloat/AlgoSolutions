#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> point;
int main() {
    int n;
    scanf("%d", &n);
    vector<point> arr(n);
    FOR(i, n) {
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    if (n < 3) {
        printf("0\n");
        return 0;
    }
    ll res = ((ll)n * (ll)(n - 1) * (ll)(n - 2)) / 6ll;
    map<point, int> mp;
    map<point, int>::iterator it;
    point tp;
    ll cnt, g;
    FOR(i, n) {
        mp.clear();
        for (int j = i + 1; j < n; ++j) {
            tp.first = arr[j].first - arr[i].first;
            tp.second = arr[j].second - arr[i].second;
            g = __gcd(abs(tp.first), abs(tp.second));
            tp.first /= g; tp.second /= g;
            if (tp.first < 0) {
                tp.first = -tp.first;
                tp.second = -tp.second;
            }
            else if (tp.first == 0) tp.second = 1;
            mp[tp] += 1;
        }
        for (it = mp.begin(); it != mp.end(); ++it) {
            cnt = it->second;
            if (cnt < 2) continue;
            res -= (cnt * (cnt - 1)) / 2ll;
        }
    }
    cout << res << endl;
    return 0;
}
