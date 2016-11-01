#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool is_vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}
int main() {
    string s;
    cin >> s;
    vector<int> pos;
    pos.push_back(0);
    FOR(i, s.size()) {
        if (is_vowel(s[i])) {
            pos.push_back(i + 1);
        }
    }
    pos.push_back((int)s.size() + 1);
    int res = -1;
    FOR(i, pos.size() - 1) {
        res = max(res, pos[i + 1] - pos[i]);
    }
    cout << res << endl;
    return 0;
}
