#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool check(string a) {
    int sz = a.size();
    return (a.substr(0, sz / 2) == a.substr(sz / 2, sz / 2));
}
int main() {
    string s;
    cin >> s;
    set<string> st;
    for (int i = 2; i <= s.size(); i += 2) {
        for (int j = 0; j + i <= s.size(); ++j) {
            st.insert(s.substr(j, i));
        }
    }
    int res = 0;
    for (auto it = st.begin(); it != st.end(); ++it) {
        if (check(*it)) {
            // cout << *it << endl;
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
