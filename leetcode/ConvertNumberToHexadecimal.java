public class Solution {

    private char int2char(int num) {
        if (num < 10) return (char) ('0' + num);
        else return (char) ('a' + (num - 10));
    }

    public String toHex(int num) {
        String res = "";
        for (int i = 7; i >= 0; --i) {
            int val = ((15 << (i * 4)) & num) >> (i * 4);
            val = (val & 15);
            char c = this.int2char(val);
            if (c != '0' || res.length() > 0) {
                res += c;
            }
        }
        if (res.isEmpty()) res = "0";
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.toHex(-1));
        System.out.println(solution.toHex(26));
        System.out.println(solution.toHex(0));
    }
}