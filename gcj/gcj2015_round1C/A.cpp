#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
void solve() {
    int row, col, w;
    int res = 0;
    cin >> row >> col >> w;
    if (col == w) {
        res = row + col - 1;
        cout << res << endl;
        return;
    }
    if (col % w == 0) {
        res = row * (col / w);
        res += w - 1;
        cout << res << endl;
        return;
    }
    else {
        res = (row - 1) * (col / w);
        res += col / w;
        res += w - 1 + 1;
        cout << res << endl;
        return;
    }
    return;
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
