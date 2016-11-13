public class Solution {

    private int calc(int n) {
        if (n < 3) return 0;
        else return n * (n + 1) / 2 - n - (n - 1);
    }

    public int numberOfArithmeticSlices(int[] A) {
        int res = 0, pv = 0;
        for (int i = 2; i < A.length; ++i) {
            int diff1 = A[i] - A[i - 1], diff2 = A[i - 1] - A[i - 2];
            if (diff1 != diff2) {
                res += calc(i - pv);
                pv = i - 1;
            }
        }
        res += calc(A.length - pv);
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numberOfArithmeticSlices(new int[]{1, 2, 3, 4}));
    }
}