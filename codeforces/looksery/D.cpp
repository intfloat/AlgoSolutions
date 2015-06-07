#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int row, col;
void change(int& x, int& y) {
    if (y == 0) {
        --x; y = col - 1;
    }
    else {
        --y;
    }
}
int main() {
    int d, res = 0;
    cin >> row >> col;
    vector<string> g(row);
    FOR(i, row) cin >> g[i];
    vector<vector<int> > board(row, vector<int>(col, 0));
    int x = row - 1, y = col - 1;
    while (true) {
        if (x < 0) break;
        if (g[x][y] == 'W' && board[x][y] == 1) {
            change(x, y);
        }
        else if (g[x][y] == 'B' && board[x][y] == -1) change(x, y);
        else if (g[x][y] == 'W') {
            d = 1 - board[x][y];
            FOR(i, x + 1) FOR(j, y + 1) board[i][j] += d;
            change(x, y);
            ++res;
        }
        else if (g[x][y] == 'B') {
            d = -1 - board[x][y];
            FOR(i, x + 1) FOR(j, y + 1) board[i][j] += d;
            change(x, y);
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
