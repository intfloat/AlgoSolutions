import java.util.Arrays;

public class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int pg = 0, ps = 0, res = 0;
        while (pg < g.length && ps < s.length) {
            if (s[ps] >= g[pg]) {
                ++pg;
                ++ps;
                ++res;
            } else {
                ++ps;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findContentChildren(new int[]{1, 2, 3}, new int[]{1, 1}));
        System.out.println(solution.findContentChildren(new int[]{1, 2}, new int[]{1, 2, 3}));
    }
}