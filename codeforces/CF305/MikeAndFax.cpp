#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
bool check(const string& s) {
    FOR(i, s.size()) {
        if (s[i] != s[s.size() - 1 - i]) return false;
    }
    return true;
}
int main() {
    string s;
    int k;
    cin >> s >> k;
    if (s.size() % k) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < s.size(); i += s.size() / k) {
        if (!check(s.substr(i, s.size() / k))) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
