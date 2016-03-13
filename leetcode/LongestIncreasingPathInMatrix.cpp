const int dir_x[] = {0, 0, 1, -1};
const int dir_y[] = {1, -1, 0, 0};
class Solution {
private:
    int row, col;
    vector<vector<int> > dp, matrix;
    int solve(int r, int c) {
        if (dp[r][c] >= 0) {
            return dp[r][c];
        }
        dp[r][c] = 1;
        for (int i = 0; i < 4; ++i) {
            int nr = r + dir_x[i], nc = c + dir_y[i];
            if (nr < 0 || nr >= row || nc < 0 || nc >= col || matrix[nr][nc] <= matrix[r][c]) {
                continue;
            }
            dp[r][c] = max(dp[r][c], 1 + solve(nr, nc));
        }
        return dp[r][c];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        this->matrix = matrix;
        row = matrix.size();
        col = matrix[0].size();
        dp.resize(row);
        for (int i = 0; i < row; ++i) {
            dp[i].resize(col);
            fill(dp[i].begin(), dp[i].end(), -1);
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res = max(res, solve(i, j));
            }
        }
        return res;
    }
};
