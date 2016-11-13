public class Solution {
    public int minMoves(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int mn = nums[0];
        for (int e : nums) {
            mn = Math.min(mn, e);
        }
        int res = 0;
        for (int e : nums) {
            res += Math.abs(mn - e);
        }
        return res;
    }
}