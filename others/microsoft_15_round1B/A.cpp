#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <string.h>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef unsigned long long ll;
ll dp[14][14][14][14][4];
bool visited[14][14][14][14][4];

ll get(int a1, int a2, int a3, int a4, int last) {
    if (!a1 && !a2 && !a3 && !a4) return 1;    
    ll res = 0ll;
    if (last >= 0 && visited[a1][a2][a3][a4][last]) return dp[a1][a2][a3][a4][last];
    if (last == -1 || last == 0) {
        if (a1 > 0) res += a1 * get(a1 - 1, a2, a3, a4, 0);
        if (a2 > 0) res += a2 * get(a1 + 1, a2 - 1, a3, a4, 1);
        if (a3 > 0) res += a3 * get(a1, a2 + 1, a3 - 1, a4, 2);
        if (a4 > 0) res += a4 * get(a1, a2, a3 + 1, a4 - 1, 3);
        if (last >= 0) {
            visited[a1][a2][a3][a4][last] = true;
            dp[a1][a2][a3][a4][last] = res;
        }
        return res;
    }
    if (last == 1 && a1 > 0) res += (a1 - 1) * get(a1 - 1, a2, a3, a4, 0);
    else if (a1 > 0) res += a1 * get(a1 - 1, a2, a3, a4, 0);
    if (last == 2 && a2 > 0) res += (a2 - 1) * get(a1 + 1, a2 - 1, a3, a4, 1);
    else if (a2 > 0) res += a2 * get(a1 + 1, a2 - 1, a3, a4, 1);
    if (last == 3 && a3 > 0) res += (a3 - 1) * get(a1, a2 + 1, a3 - 1, a4, 2);
    else if (a3 > 0) res += a3 * get(a1, a2 + 1, a3 - 1, a4, 2);
    if (a4 > 0) res += a4 * get(a1, a2, a3 + 1, a4 - 1, 3);
    visited[a1][a2][a3][a4][last] = true;
    dp[a1][a2][a3][a4][last] = res;
    return res;
}

void solve() {
    int N;
    string card;
    cin >> N;
    map<char, int> m;
    FOR(i, N) {
        cin >> card;
        ++m[card[0]];
    }    
    vector<int> cnt(4, 0);
    map<char, int>::iterator it = m.begin();
    for (; it != m.end(); ++it) ++cnt[it->second - 1];
    ll res = get(cnt[0], cnt[1], cnt[2], cnt[3], -1);
    for (it = m.begin(); it != m.end(); ++it) {
        int val = it->second;
        // assert(val >= 1 && val <= 4);
        if (val == 2) res *= 2;
        else if (val == 3) res *= 6;
        else if (val == 4) res *= 24;
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        cout << "Case #" << tt + 1 << ": ";
        solve();
    }    
    return 0;
}
