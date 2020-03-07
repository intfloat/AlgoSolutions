class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long i = 0; 2 * i * i <= c; ++i) {
            int b_sq = c - i * i;
            int rt_b = (int)sqrt(b_sq);
            if (rt_b * rt_b == b_sq) {
                return true;
            }
        }
        return false;
    }
};
