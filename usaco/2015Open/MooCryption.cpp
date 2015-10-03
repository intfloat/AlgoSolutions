#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;
int check(string s, int a, int b) {    
    int ret = 0;
    if (s.size() < 3) return 0;    
    FOR(i, s.size() - 2) {
        if ((s[i] - 'A') == a && (s[i + 1] - 'A') == b && s[i + 1] == s[i + 2]) ++ret;
    }
    reverse(s.begin(), s.end());    
    FOR(i, s.size() - 2) {
        if ((s[i] - 'A') == a && (s[i + 1] - 'A') == b && s[i + 1] == s[i + 2]) ++ret;
    }    
    return ret;
}
int main() {
    freopen("moocrypt.in", "r", stdin);
    freopen("moocrypt.out", "w", stdout);
    int row, col, res = 0;
    cin >> row >> col;
    vector<string> g(row);
    FOR(i, row) cin >> g[i];
    FOR(i, 26) FOR(j, 26) {
        if (i == j) continue;
        if (i == 'M' - 'A') continue;
        if (j == 'O' - 'A') continue;
        int cnt = 0;
        FOR(k, row) cnt += check(g[k], i, j);
        FOR(k, col) {
            string s = "";
            FOR(p, row) s += g[p][k];
            cnt += check(s, i, j);
        }
        for (int k = 0; k < row - 1 + col; ++k) {
            string s = "";
            for (int p = 0; p < row; ++p) {
                int cc = k - p;
                if (cc < 0 || cc >= col) continue;
                s += g[p][cc];
            }
            cnt += check(s, i, j);
        }
        for (int k = -col + 1; k <= row - 1; ++k) {
            string s = "";
            for (int p = 0; p < row; ++p) {
                int cc = p - k;
                if (cc < 0 || cc >= col) continue;
                s += g[p][cc];
            }
            cnt += check(s, i, j);
        }
        res = max(res, cnt);
    }
    cout << res << endl;
    return 0;
}
