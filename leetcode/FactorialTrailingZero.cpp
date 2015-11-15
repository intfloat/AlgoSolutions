class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        int cur = n;
        while (cur > 0) {
            res += cur / 5;
            cur /= 5;
        }
        return res;
    }
};
