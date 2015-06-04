#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    string s;
    string res = "";
    cin >> s;
    int val;
    FOR(i, s.size()) {
        if (s[i] == '8' || s[i] == '0') {
            cout << "YES" << endl;
            cout << s[i] << endl;
            return 0;
        }
    }
    FOR(i, s.size()) for (int j = i + 1; j < s.size(); ++j) {
        val = (s[i] - '0') * 10 + (s[j] - '0');
        if (val != 0 && val % 8 == 0) {
            cout << "YES" << endl;
            cout << s[i] << s[j] << endl;
            return 0;
        }
        else if (val == 0 && i > 0) {
            cout << "YES" << endl;
            cout << s[0] << s[i] << s[j] << endl;
            return 0;
        }
    }
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i + 1; j < s.size(); ++j) {
            for (int k = j + 1; k < s.size(); ++k) {
                val = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (val != 0 && val % 8 == 0) {
                    cout << "YES" << endl;
                    res += s[i]; res += s[j]; res += s[k];
                    cout << res << endl;
                    return 0;
                }
                else if (val == 0 && i > 0) {
                    cout << "YES" << endl;
                    res += s[0]; res += s[i]; res += s[j]; res += s[k];
                    cout << res << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
