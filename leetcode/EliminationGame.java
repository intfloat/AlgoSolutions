public class Solution {

    private int solve(int n, boolean forward) {
        if (n == 1) {
            return 1;
        }
        if (forward) {
            return 2 * solve(n / 2, !forward);
        } else if (n % 2 > 0) {
            return 2 * solve(n / 2, !forward);
        } else {
            return 2 * solve(n / 2, !forward) - 1;
        }
    }

    public int lastRemaining(int n) {
        return solve(n, true);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.lastRemaining(9)); // supposed to be 6
    }
}