public class Solution {
    public int thirdMax(int[] nums) {
        long val = Long.MIN_VALUE;
        // maximum number
        for (int i : nums) {
            val = Math.max(i, val);
        }
        // second maximum number
        long sval = Long.MIN_VALUE;
        for (int i : nums) {
            if (i < val) {
                sval = Math.max(i, sval);
            }
        }
        // third maximum number
        long tval = Long.MIN_VALUE;
        for (int i : nums) {
            if (i < sval) {
                tval = Math.max(i, tval);
            }
        }
        if (tval == Long.MIN_VALUE) {
            return (int)val;
        } else {
            return (int)tval;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.thirdMax(new int[]{3, 2, 1}));
        System.out.println(solution.thirdMax(new int[]{1, 2}));
        System.out.println(solution.thirdMax(new int[]{2, 2, 3, 1}));
    }
}