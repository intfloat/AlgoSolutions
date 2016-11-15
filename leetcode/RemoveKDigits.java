import java.util.Stack;

public class Solution {
    public String removeKdigits(String num, int k) {
        if (k >= num.length()) {
            return "0";
        }

        Stack<Character> stack = new Stack<>();
        int tk = k;
        for (int i = 0; i < num.length(); ++i) {
            while (tk > 0 && !stack.isEmpty() && num.charAt(i) < stack.peek()) {
                stack.pop();
                --tk;
            }
            stack.push(num.charAt(i));
        }
        while (stack.size() > num.length() - k) {
            stack.pop();
        }

        StringBuilder sb = new StringBuilder();
        while (!stack.isEmpty()) {
            sb.append(stack.pop());
        }
        sb.reverse();
        while (sb.length() > 1 && sb.charAt(0) == '0') {
            sb.deleteCharAt(0);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        // 11
        System.out.println(solution.removeKdigits("1173", 2));
        // 1219
        System.out.println(solution.removeKdigits("1432219", 3));
        // 200
        System.out.println(solution.removeKdigits("10200", 1));
        // 0
        System.out.println(solution.removeKdigits("10", 2));
    }
}