#include <iostream>
#include <cstdio>
#include <string>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
const string ann = "anniversary";
const int sz = ann.size();
inline void solve() {
    string s;
    cin >> s;
    for (int i = 1; i < sz; ++i) {
        string s1 = ann.substr(0, i);
        for (int j = i + 1; j < sz; ++j) {
            string s2 = ann.substr(i, j - i);
            string s3 = ann.substr(j, sz - j);
            int cnt = 0;
            for (int k = 0; k < s.size(); ++k) {
                if (cnt == 0 && k + s1.size() <= s.size() && s1 == s.substr(k, s1.size())) {
                    cnt = 1;
                    k += s1.size() - 1;
                }
                else if (cnt == 1 && k + s2.size() <= s.size() && s2 == s.substr(k, s2.size())) {
                    cnt = 2;
                    k += s2.size() - 1;
                }
                else if (cnt == 2 && k + s3.size() <= s.size() && s3 == s.substr(k, s3.size())) {
                    printf("YES\n");
                    return;
                }
            }
        }
    }
    printf("NO\n");
}
int main() {
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        solve();
    }
    return 0;
}
