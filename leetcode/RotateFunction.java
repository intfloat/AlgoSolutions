
public class Solution {
    public int maxRotateFunction(int[] A) {
        int res = 0;
        int sum = 0;
        for (int i = 0; i < A.length; ++i) {
            res += i * A[i];
            sum += A[i];
        }
        int pv = res;
        for (int i = 1; i < A.length; ++i) {
            int cur = pv - sum + A.length * A[i - 1];
            res = Math.max(res, cur);
            pv = cur;
        }
        return res;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.maxRotateFunction(new int[]{4, 3, 2, 6}));
    }
}