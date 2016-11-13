
public class Solution {

    private boolean check(long mid, int[] nums, int m) {
        long sm = 0;
        int cnt = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (sm + nums[i] > mid) {
                ++cnt;
                sm = nums[i];
            } else {
                sm += nums[i];
            }
        }
        ++cnt;
        return cnt <= m;
    }

    public int splitArray(int[] nums, int m) {
        long l = 0, r = 0;
        for (int i : nums) {
            l = Math.max(l, i);
            r += i;
        }
        while (l < r) {
            long mid = (l + r) / 2;
            if (check(mid, nums, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int)l;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.splitArray(new int[]{7,2,5,10,8}, 2));
    }
}