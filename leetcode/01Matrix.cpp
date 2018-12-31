#include <bits/stdc++.h>
using namespace std;
#define FOR(i, n) for (int i = 0; i < (int)n; ++i)
typedef long long ll;
typedef pair<int, int> pii;

int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> res(row, vector<int>(col, -1));
        queue<pair<pii, int> > q;
        FOR(i, row) FOR(j, col) {
            if (matrix[i][j] == 0) {
                res[i][j] = 0;
                q.push(make_pair(make_pair(i, j), 0));
            }
        }
        while (!q.empty()) {
            pair<pii, int> tp = q.front();
            q.pop();
            int x = tp.first.first, y = tp.first.second;
            FOR(i, 4) {
                int nx = x + dir_x[i];
                int ny = y + dir_y[i];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || res[nx][ny] >= 0) {
                    continue;
                }
                res[nx][ny] = tp.second + 1;
                q.push(make_pair(make_pair(nx, ny), res[nx][ny]));
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    return 0;
}