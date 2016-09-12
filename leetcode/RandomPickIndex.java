import java.util.stream.IntStream;

public class Solution {

    private int[] nums;

    public Solution(int[] nums) {
        this.nums = nums.clone();
    }

    public int pick(int target) {
        int pos = -1, cnt = 0;
        for (int i = 0; i < this.nums.length; ++i) {
            if (target == nums[i]) {
                ++cnt;
                if (cnt == 1) {
                    pos = i;
                } else if (Math.random() < 1.0 / cnt) {
                    pos = i;
                }
            }
        }
        return pos;
    }

    public static void main(String[] args) {
        Solution sol = new Solution(new int[]{1, 2, 3, 3, 3});
        IntStream.range(1, 10).forEach(i -> System.out.println(sol.pick(3)));
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */