#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll CN = 1000000;
void solve() {
    double number;
    cin >> number;
    vector<ll> pw(12);
    pw[0] = 1;
    vector<ll> res;
    for (int i = 1; i < 12; ++i) pw[i] = 10ll * pw[i - 1];
    for (int i = 10; i < 100; ++i) {
        double tt = i * number;
        if (fabs(tt - i / 10 - 10 * (i % 10)) < 1e-8) {
            res.push_back(i);
        }
    }
    ll tn = (ll)(number * CN + 0.1);
    for (int t = 2; t < 10; ++t) {
        for (ll h = 1; h < 10; ++h) {
            for (ll low = 0; low < 10; ++low) {
                ll num = (CN * low * pw[t] + CN * h - tn * (h * pw[t] + low));
                ll den = (10 * tn - 10ll * CN);
                ll t1 = num, t2 = den;
                if (t1 % t2 == 0 && t1 / t2 < pw[t - 1] && t1 / t2 >= 0) {
                    res.push_back(t1 / t2 * 10 + h * pw[t] + low);
                }
            }
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        if (i + 1 < res.size()) cout << res[i] << " ";
        else cout << res[i];
    }
    if (!res.empty()) cout << endl;
    return;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Case #" << i + 1 << ":" << endl;
        solve();
    }
    return 0;
}
