class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;
        }
        int r = m, c = n;
        for (int i = 0; i < ops.size(); ++i) {
            int nr = ops[i][0], nc = ops[i][1];
            r = min(r, nr);
            c = min(c, nc);
        }
        return r * c;
    }
};
