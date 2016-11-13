public class Solution {
    public int longestPalindrome(String s) {
        int[] cnt = new int[256];
        for (int i = 0; i < s.length(); ++i) {
            ++cnt[s.charAt(i)];
        }
        int res = 0;
        for (int i : cnt) {
            res += i / 2 * 2;
        }
        return Math.min(res + 1, s.length());
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.longestPalindrome("abccccdd"));
    }
}