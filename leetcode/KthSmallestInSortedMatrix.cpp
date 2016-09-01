class Solution {
private:
    int n;
    int get(vector<vector<int>>& matrix, int val) {
        int cnt = 0, pos = n - 1;
        for (int i = 0; i < n; ++i) {
            while (pos >= 0 && matrix[i][pos] > val) --pos;
            if (pos < 0) {
                return cnt;
            } else {
                cnt += pos + 1;
            }
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        n = matrix.size();
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        while (l < r) {
            int mid = l + (r - l) / 2;
            int cc = get(matrix, mid);
            if (cc >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
