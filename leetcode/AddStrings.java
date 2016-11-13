public class Solution {
    public String addStrings(String num1, String num2) {
        if (num1.length() == 0) return num2;
        else if (num2.length() == 0) return num1;
        int m = num1.length() - 1, n = num2.length() - 1, carry = 0;
        String res = "";
        while (carry > 0 || m >= 0 || n >= 0) {
            int sm = carry;
            if (m >= 0) sm += num1.charAt(m) - '0';
            if (n >= 0) sm += num2.charAt(n) - '0';
            --m;
            --n;
            res = (sm % 10) + res;
            carry = sm / 10;
        }
        if (res.isEmpty()) res = "0";
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.addStrings("1234", "78")); // should be "1312"
    }
}