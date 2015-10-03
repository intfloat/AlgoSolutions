#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>
#include <cassert>
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;
int main() {
    freopen("skicourse.in", "r", stdin);
    freopen("skicourse.out", "w", stdout);
    int row, col;
    vector<string> g;    
    cin >> row >> col;
    vector<vector<bool> > smooth(row, vector<bool>(col)), rough(row, vector<bool>(col));
    g.resize(row);
    FOR(i, row) cin >> g[i];
    FOR(i, row) FOR(j, col) {
        smooth[i][j] = (g[i][j] == 'S');
        rough[i][j] = (g[i][j] == 'R');
    }
    vector<vector<int> > sdp(row, vector<int>(col)), rdp(row, vector<int>(col));
    int res = min(row, col);
    while (true) {
        int mx = -1;
        pair<int, int> pos = make_pair(-1, -1);
        FOR(i, row) {
            fill(sdp[i].begin(), sdp[i].end(), 0);
            fill(rdp[i].begin(), rdp[i].end(), 0);
        }
        FOR(i, row) FOR(j, col) {
            if (smooth[i][j]) {
                if (i == 0 || j == 0) sdp[i][j] = 1;
                else sdp[i][j] = min(sdp[i - 1][j - 1], min(sdp[i - 1][j], sdp[i][j - 1])) + 1;
            }
            if (rough[i][j]) {
                if (i == 0 || j == 0) rdp[i][j] = 1;
                else rdp[i][j] = min(rdp[i - 1][j - 1], min(rdp[i - 1][j], rdp[i][j - 1])) + 1;
            }
            // if they are equal, then they've been checked before.
            if (sdp[i][j] != rdp[i][j]) {
                int cur = max(sdp[i][j], rdp[i][j]);
                if (cur > mx) {
                    mx = cur;
                    pos = make_pair(i, j);
                }
            }
        }
        if (mx == -1) {
            cout << res << endl;
            break;
        }
        else res = min(res, mx);        
        for (int i = pos.first - mx + 1; i <= pos.first; ++i)
            for (int j = pos.second - mx + 1; j <= pos.second; ++j)
                smooth[i][j] = rough[i][j] = true;
    }
    return 0;
}
