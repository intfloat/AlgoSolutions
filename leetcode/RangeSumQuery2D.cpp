class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = (row > 0)? matrix[0].size(): 0;
        data.resize(row + 1);
        for (int i = 0; i <= row; ++i) {
            data[i].resize(col + 1);
            fill(data[i].begin(), data[i].end(), 0);
        }
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                data[i][j] = data[i][j - 1] + data[i - 1][j] - data[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        ++row1; ++row2; ++col1; ++col2;
        return data[row2][col2] - data[row1 - 1][col2] - data[row2][col1 - 1] + data[row1 - 1][col1 - 1];
    }
private:
    vector<vector<int> > data;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
