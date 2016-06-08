public class Solution {
    public boolean isPowerOfFour(int num) {
        while (num != 0 && num % 4 == 0) {
            num /= 4;
        }
        return (num == 1);
    }
}
