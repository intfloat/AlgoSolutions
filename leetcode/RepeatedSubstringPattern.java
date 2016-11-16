public class Solution {
    public boolean repeatedSubstringPattern(String str) {
        for (int i = 1; i < str.length(); ++i) {
            if (str.length() % i != 0) {
                continue;
            }
            boolean ok = true;
            for (int j = 0; j < str.length(); ++j) {
                if (str.charAt(j) != str.charAt(j % i)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.repeatedSubstringPattern("abab"));
        System.out.println(solution.repeatedSubstringPattern("aba"));
        System.out.println(solution.repeatedSubstringPattern("abcabcabcabc"));
    }
}