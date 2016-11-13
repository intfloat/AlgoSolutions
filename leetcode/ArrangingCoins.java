public class Solution {
    public int arrangeCoins(int n) {
        if (n <= 0) {
            return 0;
        }
        for (long i = 1; ; ++i) {
            long cur = i * (i + 1) / 2;
            if (cur > n) {
                return (int)(i - 1);
            }
        }
    }
}