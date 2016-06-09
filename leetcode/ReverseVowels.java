public class Solution {
    public String reverseVowels(String s) {
        if (s.isEmpty()) {
            return new String();
        }
        char[] chArr = new char[s.length()];
        int l = 0, r = s.length() - 1;
        while (l < r) {
            while (l < r && !isVowel(s.charAt(l))) {
                chArr[l] = s.charAt(l);
                ++l;
            }
            while (r > l && !isVowel(s.charAt(r))) {
                chArr[r] = s.charAt(r);
                --r;
            }
            if (l < r) {
                chArr[l] = s.charAt(r);
                chArr[r] = s.charAt(l);
                ++l;
                --r;
            }
        }
        if (l == r) {
            chArr[l] = s.charAt(l);
        }
        return new String(chArr);
    }

    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'o' || c =='u' || c == 'i'
                || c == 'A' || c == 'E' || c == 'O' || c =='U' || c == 'I';
    }
}
