#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int dir_x[] = {-1, 1, 0, 0};
const int dir_y[] = {0, 0, 1, -1};
int get(char c) {
    if (c == '^') return 0;
    if (c == 'v') return 1;
    if (c == '>') return 2;
    if (c == '<') return 3;
    assert(false);
    return -1;
}

string g[205];
void solve() {
    int row, col, nx, ny;
    cin >> row >> col;
    FOR(i, row) cin >> g[i];
    int idx = 2;
    map<pair<int, int>, int> mp;
    FOR(i, row) FOR(j, col) {
        if (g[i][j] != '.') mp[make_pair(i, j)] = idx++;
    }
    if (mp.size() == 1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    if (mp.size() == 0) { cout << 0 << endl; return; }
    int start = mp.size() + 5;
    int pp, res = 0;
    FOR(i, row) FOR(j, col) {
        if (g[i][j] == '.') continue;
        int x = i, y = j;
        pair<int, int> from = make_pair(i, j);        
        int cc = get(g[i][j]);
        set<int> st;
        FOR(k, 4) {
            nx = x + dir_x[k]; ny = y + dir_y[k];
            while (nx < row && ny < col && nx >= 0 && ny >= 0 && g[nx][ny] == '.') {
                nx += dir_x[k]; ny += dir_y[k];
            }
            pair<int, int> t = make_pair(nx, ny);
            if (mp.find(t) != mp.end()) {
                st.insert(k);                
            }
        }
        if (st.empty()) { cout << "IMPOSSIBLE" << endl; return; }
        else res += (st.find(cc) == st.end());
    }
    cout << res << endl; return;    
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
