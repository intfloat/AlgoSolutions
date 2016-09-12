public class Solution {
    public int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        } else if (n % 2 == 0) {
            return integerReplacement(n / 2) + 1;
        } else {
            int n1 = (n - 1) / 2;
            int n2 = (int)(((long)n + 1l) / 2);
            return Math.min(integerReplacement(n1), integerReplacement(n2)) + 2;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.integerReplacement(2147483647));
    }
}