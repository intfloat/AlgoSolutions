#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;

string change(string& s) {
    bool ok = false;
    string ret = "";
    FOR(i, s.size()) {
        if (ok || s[i] != '0') { ret += s[i]; ok = true; }
    }
    return ret;
}

int main() {
    string s;
    cin >> s;
    vector<string> res;
    while (true) {
        string cur = "";
        bool ok = false;
        FOR(i, s.size()) {
            if (s[i] == '0') { cur += '0'; }
            else { cur += '1'; --s[i]; ok = true; }
        }
        if (!ok) break;
        else res.push_back(cur);
    }
    cout << res.size() << endl;
    FOR(i, res.size()) cout << change(res[i]) << " ";
    cout << endl;
    return 0;
}
