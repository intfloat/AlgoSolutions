#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    vector<int> a(26, 0), b(26, 0), c(26, 0);
    char s[100005];
    string sa, sb, sc;
    scanf("%s", s); sa = s;
    for (int i = 0; s[i]; ++i) ++a[s[i] - 'a'];
    scanf("%s", s); sb = s;
    for (int i = 0; s[i]; ++i) ++b[s[i] - 'a'];
    scanf("%s", s); sc = s;
    for (int i = 0; s[i]; ++i) ++c[s[i] - 'a'];
    int res = 0;
    pair<int, int> pp = make_pair(0, 0);
    int up = accumulate(a.begin(), a.end(), 0);
    vector<int> tt(26);
    for (int i = 0; i <= up; ++i) {
        bool ok = true;
        FOR(j, 26) {
            if (i * b[j] > a[j]) {
                ok = false;
                break;
            }
            else tt[j] = a[j] - i * b[j];
        }
        if (!ok) break;
        int val = up;
        FOR(j, 26) {
            if (c[j] > 0) {
                val = min(val, tt[j] / c[j]);
            }
        }
        if (val + i > res) {
            res = val + i;
            pp = make_pair(i, val);
        }
    }
    FOR(i, pp.first) cout << sb;
    FOR(i, pp.second) cout << sc;
    FOR(i, 26) FOR(j, a[i] - pp.first * b[i] - pp.second * c[i]) cout << (char)('a' + i);
    cout << endl;
    return 0;
}
