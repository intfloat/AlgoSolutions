#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;


int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};

class Solution {
private:
    vector<vector<bool> > visited;
    int bfs(vector<vector<int> >& grid, int r, int c) {
        queue<pii> q;
        q.push({r, c});
        visited[r][c] = true;
        int area = 1;

        while (!q.empty()) {
            pii tp = q.front();
            q.pop();
            FOR(i, 4) {
                int nr = tp.first + dir_x[i];
                int nc = tp.second + dir_y[i];
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size()) continue;
                if (visited[nr][nc] || grid[nr][nc] == 0) continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
                ++area;
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();
        this->visited = vector<vector<bool> >(row, vector<bool>(col, false));

        int res = 0;
        FOR(i, row) FOR(j, col) {
            if (visited[i][j] || grid[i][j] == 0) continue;
            res = max(res, bfs(grid, i, j));
        }
        return res;
    }
};
