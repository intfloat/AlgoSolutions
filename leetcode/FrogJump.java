public class Solution {
    private int n;
    private int[] stones;
    private int[][] dp;

    private boolean ok(int i, int k) {
        if (i + 1 == this.n) {
            return true;
        }
        if (this.dp[i][k] != -1) {
            return this.dp[i][k] == 1;
        }
        this.dp[i][k] = 0;
        for (int j = i + 1; j < this.n && this.stones[j] - this.stones[i] <= k + 1; ++j) {
            int diff = this.stones[j] - this.stones[i];
            if (diff >= k - 1 && diff <= k + 1) {
                boolean res = ok(j, diff);
                if (res) {
                    this.dp[i][k] = 1;
                    break;
                }
            }
        }
        return this.dp[i][k] == 1;
    }

    public boolean canCross(int[] stones) {
        if (stones.length > 1 && stones[1] != 1) {
            return false;
        }
        this.stones = stones;
        this.n = stones.length;
        this.dp = new int[this.n][this.n];
        for (int i = 0; i < this.n; ++i) {
            for (int j = 0; j < this.n; ++j) {
                this.dp[i][j] = -1;
            }
        }
        return ok(1, 1);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.canCross(new int[]{0,1,3,5,6,8,12,17}));
        System.out.println(solution.canCross(new int[]{0,1,2,3,4,8,9,11}));
        System.out.println(solution.canCross(new int[]{0,2}));
    }
}