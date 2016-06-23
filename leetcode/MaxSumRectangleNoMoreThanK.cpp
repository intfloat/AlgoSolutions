class Solution {
private:
    vector<vector<int> > transpose(vector<vector<int> > m) {
        int row = m.size();
        int col = m[0].size();
        vector<vector<int> > ret(col, vector<int>(row));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                ret[j][i] = m[i][j];
            }
        }
        return ret;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row > col) {
            swap(row, col);
            matrix = transpose(matrix);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                matrix[i][j] += (i > 0) ? matrix[i - 1][j] : 0;
            }
        }
        int res = INT_MIN;
        for (int i = 0; i < row; ++i) {
            for (int j = i; j < row; ++j) {
                vector<int> arr(col, 0);
                for (int p = 0; p < col; ++p) {
                    arr[p] = matrix[j][p] - ((i > 0) ? matrix[i - 1][p] : 0);
                    arr[p] += (p > 0) ? arr[p - 1] : 0;
                }
                set<int> st;
                st.insert(0);
                for (int p = 0; p < col; ++p) {
                    auto it = st.lower_bound(arr[p] - k);
                    if (it != st.end()) {
                        res = max(res, arr[p] - *it);
                    }
                    st.insert(arr[p]);
                }
            }
        }
        return res;
    }
};
