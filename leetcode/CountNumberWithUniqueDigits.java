public class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= Math.min(10, n); ++i) {
            res += get(i);
        }
        return res;
    }

    private int get(int num) {
        int ret = 1;
        for (int i = 0; i < num; ++i) {
            ret *= (10 - i);
        }
        if (num > 1) {
            ret = ret / 10 * 9;
        }
        return ret;
    }
}
