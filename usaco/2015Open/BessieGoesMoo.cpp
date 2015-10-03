#include <iostream>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef unsigned long long ll;
const char cs[] = {'B', 'E', 'S', 'I', 'G', 'O', 'M'};
int main() {
    freopen("bgm.in", "r", stdin);
    freopen("bgm.out", "w", stdout);
    int N, number;
    char c;
    cin >> N;
    vector<vector<ll> > cnt(26, vector<ll>(7, 0ll));
    FOR(i, N) {
        cin >> c >> number;        
        number = (number % 7 + 7) % 7;
        ++cnt[c - 'A'][number];
    }
    ll total = 1ll;
    FOR(i, 7) {
        ll cur = 0;
        FOR(j, 7) cur += cnt[cs[i] - 'A'][j];
        total *= cur;
    }
    ll res = 0ll;
    FOR(x1, 7) FOR(x2, 7) FOR(x3, 7) FOR(x4, 7) FOR(x5, 7) FOR(x6, 7) FOR(x7, 7) {
        // B E S I G O M
        ll cur = (x1 + 2 * x2 + 2 * x3 + x4) * (x5 + x6 + x2 + x3) * (x7 + 2 * x6);
        if (cur % 7) {
            res += cnt['B' - 'A'][x1] * cnt['E' - 'A'][x2] * cnt['S' - 'A'][x3] * cnt['I' - 'A'][x4]
                    * cnt['G' - 'A'][x5] * cnt['O' - 'A'][x6] * cnt['M' - 'A'][x7];
        }
    }
    cout << total - res << endl;
    return 0;
}
