#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    int N, mx;
    string s;
    cin >> N;
    FOR(tt, N) {
        cin >> mx >> s;
        assert(s.size() == mx + 1);
        int res = 0;
        for (res = 0; res <= mx; ++res) {
            int val = res + (s[0] - '0');
            bool ok = true;
            for (int i = 1; i <= mx; ++i) {
                if (val >= i) {
                    val += s[i] - '0';
                    continue;
                }
                else {
                    ok = false;
                    break;
                }
            }
            if (ok) { cout << "Case #" << tt + 1 << ": " << res << endl; break; }
        } 
    }
    return 0;
}
