#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    string s, t, p;
    cin >> s >> t;
    int cnt = 0;
    FOR(i, s.size()) {
        if (s[i] == t[i]) p += s[i];
        else if (cnt % 2) {
            p += s[i];
            ++cnt;
        }
        else {
            p += t[i];
            ++cnt;
        }
    }
    if (cnt % 2) cout << "impossible" << endl;
    else cout << p << endl;
    return 0;
}
