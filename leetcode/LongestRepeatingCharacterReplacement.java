public class Solution {
    public int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int l = 0, r = 0, res = 0;
        while (r < s.length()) {
            ++cnt[s.charAt(r) - 'A'];
            int mx = 0;
            for (int i = 0; i < 26; ++i) {
                mx = Math.max(mx, cnt[i]);
            }
            if (r - l + 1 - mx <= k) {
                res = Math.max(res, r - l + 1);
                ++r;
            } else {
                --cnt[s.charAt(l) - 'A'];
                --cnt[s.charAt(r) - 'A'];
                ++l;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.characterReplacement("ABAB", 2));
        System.out.println(solution.characterReplacement("AABABBA", 1));
    }
}