class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> > dp(row, vector<int>(col));
        for (int i = 0; i < row; ++i) dp[i][0] = (matrix[i][0] == '1');
        for (int i = 0; i < col; ++i) dp[0][i] = (matrix[0][i] == '1');
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == '1') dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                else dp[i][j] = 0;
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};
