class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int dr = -1, dc = 1;
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) {
            return res;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        int r = 0, c = 0;
        while (res.size() < row * col) {
            res.push_back(matrix[r][c]);
            int nr = r + dr, nc = c + dc;
            if (nr < 0 && nc == col) {
                dr = 1;
                dc = -1;
                ++r;
            } else if (nr == row && nc < 0) {
                dr = -1;
                dc = 1;
                ++c;
            } else if (nr < 0) {
                dr = 1;
                dc = -1;
                ++c;
            } else if (nc < 0) {
                dr = -1;
                dc = 1;
                ++r;
            } else if (nr == row) {
                dr = -1;
                dc = 1;
                ++c;
            } else if (nc == col) {
                dr = 1;
                dc = -1;
                ++r;
            } else {
                r = nr;
                c = nc;
            }
        }
        return res;
    }
};
