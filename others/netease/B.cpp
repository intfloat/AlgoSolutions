#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int get(ll N, int pos) {
    if (N & (1ll << pos)) return 1;
    else return 0;
}
int main() {
    ll N;
    cin >> N;
    int cnt = get(N, 0);
    for (int i = 1; i < 40; ++i) {
        if (!get(N, i) && get(N, i - 1)) {
            ll res = N + (1ll << i) - (N % (1ll << i));
            // cout << res << endl;
            --cnt;
            res += (1ll << cnt) - 1ll;
            cout << res << endl;
            break;
        } else {
            cnt += get(N, i);
        }
    }
    return 0;
}
