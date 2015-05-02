#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
void solve() {
    string s;
    cin >> s;
    // cout << s << " ";
    int len = s.size();
    if (len == 1) {
        cout << s[0] - '0' << endl;
        return;
    }
    if (len == 2 && s[0] == '1') {
        cout << s << endl;
        return;
    }
    ll res = 0ll;
    for (int i = 1; i <= len - 1; ++i) {
        ll start = 1ll;
        ll cur = 0ll;
        for (int j = 0; j < i / 2; ++j) {
            cur += 9 * start;
            start *= 10;
        }
        cur = cur + cur;
        if (i % 2 == 1) cur += start * 9;
        res += cur;
        ++res;
    }
    if (len == 3 && s[0] == '1') {
        res += (s[1] - '0') * 10 + (s[2] - '0');
        cout << res << endl;
        return;
    }
    int pos = len - 1;
    while (s[pos] == '0') --pos;
    if (pos == 0 && s[0] == '1') {
        cout << res << endl;
        return;
    }    
    // special case
    if (pos <= (len - 1) / 2) {
        ++res;
        --s[pos];
        for (int i = pos + 1; i < len; ++i) s[i] = '9';
    }
    int sm = 0;
    for (int i = 0; i < len / 2; ++i) sm += s[i] - '0';
    if (sm == 1) --res;
    // cout << "DEBUG: " << res << endl;
    ll val = 0ll;
    ll start = 1ll;
    for (int i = 0; i < len / 2; ++i) {
        val += (s[i] - '0') * start;
        start *= 10;
    }
    if (len % 2 == 1) val += (s[len / 2] - '0') * start;
    res += val;
    val = 0ll; start = 1ll;
    for (int i = 0; i < len / 2; ++i) {
        val += (s[len - 1 - i] - '0') * start;
        start *= 10;
    }
    res += val;
    cout << res << endl;
    return;
}

int main() {
    int TestCase;
    cin >> TestCase;
    FOR(caseID, TestCase) {
        cout << "Case #" << caseID + 1 << ": ";
        solve();
    }
    return 0;
}
