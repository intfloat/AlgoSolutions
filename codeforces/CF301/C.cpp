#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
const int dir_x[] = {0, 0, -1, 1};
const int dir_y[] = {1, -1, 0, 0};
int main() {
    int row, col, sr, sc, dr, dc;
    cin >> row >> col;
    vector<string> g(row);
    FOR(i, row) cin >> g[i];
    cin >> sr >> sc >> dr >> dc;
    --sr; --sc; --dr; --dc;
    int cnt = 0;
    FOR(i, 4) {
        int nr = dr + dir_x[i];
        int nc = dc + dir_y[i];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == 'X') continue;
        ++cnt;
    }
    int diff = abs(sr - dr) + abs(sc - dc);
    if (diff == 0) {        
        if (cnt > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (diff == 1) {
        if (g[dr][dc] == 'X') cout << "YES" << endl;
        else if (cnt > 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    q.push(make_pair(sr, sc)); visited[sr][sc] = true;
    bool reach = false;
    while (!q.empty()) {
        pair<int, int> tp = q.front(); q.pop();        
        FOR(i, 4) {
            int nr = tp.first + dir_x[i];
            int nc = tp.second + dir_y[i];
            if (nr == dr && nc == dc) { reach = true; break; }
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || g[nr][nc] == 'X' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push(make_pair(nr, nc));
        }
        if (reach) break;
    }
    if (!reach) cout << "NO" << endl;
    else if (g[dr][dc] == 'X') cout << "YES" << endl;
    else if (cnt >= 2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
