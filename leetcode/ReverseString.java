public class Solution {
    public String reverseString(String s) {
        if (s.isEmpty()) {
            return new String();
        }
        char[] chArr = new char[s.length()];
        for (int i = 0; i < s.length(); ++i) {
            chArr[i] = s.charAt(s.length() - 1 - i);
        }
        return new String(chArr);
    }
}
