import java.util.Arrays;

public class Solution {
    public boolean canPartition(int[] nums) {
        int sm = 0;
        for (int e : nums) {
            sm += e;
        }
        if (sm % 2 > 0) {
            return false;
        }
        boolean[] ok = new boolean[sm / 2 + 1];
        Arrays.fill(ok, false);
        ok[0] = true;
        for (int e : nums) {
            for (int i = ok.length - 1; i >= e; --i) {
                ok[i] = ok[i] || ok[i - e];
            }
        }
        return ok[sm / 2];
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canPartition(new int[]{1, 5, 11, 5}));
        System.out.println(solution.canPartition(new int[]{1, 2, 3, 5}));
    }
}