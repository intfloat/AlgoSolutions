#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
char s[100005], a[105], b[105];
ll MOD = (ll)(1e9 + 7), base = 29, bias = 97;
int msearch(string& s1, string& s2) {
    if (s1.size() < s2.size() || s2.empty()) {
        return -1;
    }
    ll h1 = 0, h2 = 0;
    FOR(i, s2.size()) {
        h2 = (h2 * base + (s2[i] - 'a')) % MOD;
        h1 = (h1 * base + (s1[i] - 'a')) % MOD;
    }
    ll pw = 1;
    FOR(i, s2.size() - 1) {
        pw = (pw * base) % MOD;
    }
    for (int i = (int)s2.size(); i <= (int)s1.size(); ++i) {
        if (h1 == h2) {
            // cout << s1 << " " << s2 << " " << i - s2.size() << endl;
            int ans = i - s2.size();
            return ans;
            // if (s2 == s1.substr(ans, s2.size())) return ans;
        }
        if (i == (int)s1.size()) return -1;
        else {
            h1 -= pw * (s1[i - s2.size()] - 'a');
            h1 %= MOD;
            h1 = (h1 + MOD) % MOD;

            h1 = (h1 * base + s1[i] - 'a') % MOD;
        }
    }
    return -1;
}
int main() {
    while (scanf("%s %s %s", s, a, b) != EOF) {
        bool forward = false, backward = false;
        string s1(s), s2(a);
        int pos = msearch(s1, s2);
        if (pos >= 0) {
            s1 = s + pos + s2.size();
            s2 = b;
            forward = (msearch(s1, s2) >= 0);
        }
        s1 = s;
        reverse(s1.begin(), s1.end());
        reverse(s, s + s1.size());
        s2 = a;
        pos = msearch(s1, s2);
        if (pos >= 0) {
            s1 = s + pos + s2.size();
            s2 = b;
            backward = (msearch(s1, s2) >= 0);
        }
        if (forward && backward) printf("both\n");
        else if (forward) printf("forward\n");
        else if (backward) printf("backward\n");
        else printf("invalid\n");
    }
    return 0;
}
