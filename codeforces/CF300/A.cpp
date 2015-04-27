#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    string res = "CODEFORCES";
    string s;
    cin >> s;
    FOR(i, s.size()) {
        string t = s.substr(i, s.size() - i);
        if (t == res) { cout << "YES" << endl; return 0; }
        t = s.substr(0, i + 1);
        if (t == res) { cout << "YES" << endl; return 0; }
    }
    FOR(i, s.size()) for (int j = i + 1; j < s.size(); ++j) {
        string t = s.substr(0, i + 1) + s.substr(j, s.size() - j);
        if (t == res) { cout << "YES" << endl; return 0; }
    }
    cout << "NO" << endl;
    return 0;
}
