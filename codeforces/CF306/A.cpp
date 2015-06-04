#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
string s;
int main() {
    vector<int> v1, v2;
    cin >> s;
    FOR(i, s.size() - 1) {
        if (s[i] == 'A' && s[i + 1] == 'B') v1.push_back(i);
        if (s[i] == 'B' && s[i + 1] == 'A') v2.push_back(i);
    }
    bool ok = false;
    if (!v1.empty() && !v2.empty()) {
        if (v1[0] + 2 <= v2.back() || v2[0] + 2 <= v1.back()) ok = true;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
