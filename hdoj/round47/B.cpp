#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
#include <cstdio>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> point;
using namespace std;
vector<ll> monster;
vector<ll> gun;
inline void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    gun.resize(n);
    monster.resize(m);
    FOR(i, n) {
        scanf("%lld", &gun[i]);
    }
    FOR(i, m) {
        scanf("%lld", &monster[i]);
    }
    sort(gun.begin(), gun.end());
    sort(monster.begin(), monster.end());
    ll cnt = 0;
    int ptr = 0;
    FOR(i, n) {
        if (ptr == monster.size()) {
            break;
        }
        if (gun[i] >= monster[ptr]) {
            ++cnt;
            ++ptr;
        }
    }
    reverse(gun.begin(), gun.end());
    ll res = gun[0] - monster[0];
    for (int i = 1; i < cnt; ++i) {
        gun[i] += gun[i - 1];
        monster[i] += monster[i - 1];
        res = max(res, gun[i] - monster[i]);
    }
    cout << res << endl;
    return;
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(tt, T) {
        solve();
    }
    return 0;
}
