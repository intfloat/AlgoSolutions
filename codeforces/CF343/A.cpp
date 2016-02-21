#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int main() {
    int n;
    cin >> n;
    vector<string> g(n);
    FOR(i, n) cin >> g[i];
    int res = 0;
    FOR(i, n) {
        int cnt = 0;
        FOR(j, n) cnt += (g[i][j] == 'C');
        res += cnt * (cnt - 1) / 2;
    }
    FOR(j, n) {
        int cnt = 0;
        FOR(i, n) cnt += (g[i][j] == 'C');
        res += cnt * (cnt - 1) / 2;
    }
    cout << res << endl;
    return 0;
}
