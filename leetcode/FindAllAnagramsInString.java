import java.util.ArrayList;
import java.util.List;

public class Solution {

    private boolean equal(int[] a, int[] b) {
        for (int i = 0; i < 26; ++i) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int[] pcnt = new int[26];
        int[] scnt = new int[26];
        for (int i = 0; i < p.length(); ++i) {
            ++pcnt[p.charAt(i) - 'a'];
        }
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i + p.length() - 1 < s.length(); ++i) {
            if (i == 0) {
                for (int j = 0; j < p.length(); ++j) {
                    ++scnt[s.charAt(j) - 'a'];
                }
            } else {
                --scnt[s.charAt(i - 1) - 'a'];
                ++scnt[s.charAt(i + p.length() - 1) - 'a'];
            }
            if (this.equal(scnt, pcnt)) {
                res.add(i);
            }
        }
        return res;
    }
}