// MaximalRectangle.cpp
class Solution {
public:
    // O(N^3) solution
    int maximalRectangle(vector<vector<char> > &matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        int** c = new int*[row];
        for (int i=0; i<row; i++) c[i] = new int[col];
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                if (matrix[i][j]=='0') c[i][j] = 0;
                else if (i == 0) c[i][j] = 1;
                else c[i][j] = c[i-1][j]+1;
            }
        }
        int res = 0;
        for (int i=0; i<row; i++) {
            for (int j=0; j<col; j++) {
                int h = c[i][j];
                for (int k=j; k>=0; k--) {
                    if (matrix[i][k] == '0') break;
                    h = min(h, c[i][k]);
                    res = max(res, (j-k+1)*h);
                }
            }
        }
        return res;
    }
};