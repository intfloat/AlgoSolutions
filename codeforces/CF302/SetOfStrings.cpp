#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int main() {
    int k;
    cin >> k;
    string p;
    cin >> p;
    set<char> s;
    FOR(i, p.size()) {
        s.insert(p[i]);
        if (s.size() == k) break;
    }
    if (s.size() < k) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        int start = 0;
        s.erase(p[0]);
        for (int i = 1; i < p.size(); ++i) {
            if (s.find(p[i]) != s.end()) {
                cout << p.substr(start, i - start) << endl;
                start = i;
                s.erase(p[i]);
            }
        }
        cout << p.substr(start, p.size() - start) << endl;
    }
    return 0;
}
