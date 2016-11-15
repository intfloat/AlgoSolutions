public class Solution {

    private final String[] digits = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    private int[] rcnt, ccnt;

    private void update(int num, char c) {
        this.rcnt[num] = this.ccnt[c - 'a'];
        for (int i = 0; i < digits[num].length(); ++i) {
            this.ccnt[digits[num].charAt(i) - 'a'] -= this.rcnt[num];
        }
    }

    public String originalDigits(String s) {
        this.ccnt = new int[26];
        this.rcnt = new int[10];
        for (int i = 0; i < s.length(); ++i) {
            ++this.ccnt[s.charAt(i) - 'a'];
        }
        this.update(0, 'z');
        this.update(2, 'w');
        this.update(4, 'u');
        this.update(6, 'x');
        this.update(8, 'g');
        this.update(7, 's');
        this.update(5, 'v');
        this.update(3, 't');
        this.update(1, 'o');
        this.update(9, 'i');
        String res = "";
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < this.rcnt[i]; ++j) {
                res += String.valueOf(i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.originalDigits("owoztneoer"));
        System.out.println(solution.originalDigits("fviefuro"));
    }
}