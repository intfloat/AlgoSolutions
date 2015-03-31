#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

int main() {
    string s;
    cin >> s;    
    FOR(i, s.size()) {
        if (i == 0 && s[i] == '9') continue;
        if (s[i] >= '5') s[i] = '0' + ('9' - s[i]);        
    }
    bool zero = false;
    FOR(i, s.size()) {
        if (s[i] != '0' || zero) {
            cout << s[i];
            zero = true;
        }
    }
    if (!zero) cout << "9";
    cout << endl;
    return 0;
}
