#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
char s[10005];
inline void solve() {
    scanf("%s", s);
    string res;
    int sz = strlen(s);
    FOR(i, sz) {
        if (s[i] == '0') {
            if (!res.empty()) {
                res.push_back(s[i]);
            }
        }
        else if (s[i] == '1' && s[i + 1] == '1') {
            if (res.empty()) {
                res.push_back('1');
                for (int j = i; j < sz; ++j) res.push_back('0');
            }
            else {
                // res.back() = '1';
                int pos = res.size() - 1;
                while (pos - 1 >= 0 && res[pos] == '0' && res[pos - 1] == '1') {
                    res[pos] = res[pos - 1] = '0';
                    pos -= 2;
                }
                if (pos < 0) res = "1" + res;
                else res[pos] = '1';
                for (int j = i; j < sz; ++j) res.push_back('0');
            }
            break;
        }
        else {
            assert(s[i] == '1' && s[i + 1] != '1');
            res.push_back(s[i]);
        }
    }
    if (res.empty()) res.push_back('0');
    printf("%s\n", res.c_str());
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
