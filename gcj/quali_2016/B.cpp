#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
string s;
int flip(int pos, char ch) {
    if (pos < 0) return 0;
    while (pos >= 0 && s[pos] == ch) --pos;
    char cc;
    if (ch == '+') cc = '-';
    else cc = '+';
    if (pos < 0) return 0;
    return flip(pos, cc) + 1;
}
void solve() {
    cin >> s;
    int len = s.size();
    printf("%d\n", flip(len - 1, '+'));
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
