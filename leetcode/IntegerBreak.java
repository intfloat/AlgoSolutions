// see https://leetcode.com/discuss/102706/an-simple-explanation-of-the-math-part-and-a-o-n-solution
// for detailed explanation
public class Solution {
    public int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        return res * n;
    }
}
