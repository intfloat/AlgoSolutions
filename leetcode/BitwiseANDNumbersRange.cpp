class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0, cnt = n - m + 1;
        for (int i = 0; i < 31; ++i) {
            int val = (1 << i);
            if (cnt > val) continue;
            int t = (n >> i) & (m >> i) & 1;
            res |= (t << i);
        }
        return res;
    }
};
