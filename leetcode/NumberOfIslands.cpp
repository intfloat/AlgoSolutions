#include <queue>
#include <utility>

const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
const char ISLAND = '1';
const char WATER = '0';

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.size() == 0) return 0;
        int row = grid.size(), col = grid[0].size();
        int res = 0;
        vector<vector<bool> > visited(row, vector<bool>(col, false));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (visited[i][j] || grid[i][j] == WATER) continue;
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                while (!q.empty()) {
                    pair<int, int> tp = q.front(); q.pop();
                    int x = tp.first, y = tp.second;
                    for (int k = 0; k < 4; ++k) {
                        int xx = x + dir_x[k];
                        int yy = y + dir_y[k];
                        if (xx < 0 || xx >= row || yy < 0 || yy >= col) continue;
                        if (visited[xx][yy] || grid[xx][yy] != ISLAND) continue;
                        visited[xx][yy] = true;
                        q.push(make_pair(xx, yy));
                    }
                }
                ++res;
            } // end inner for loop
        } // end outer for loop
        return res;
    }
};
