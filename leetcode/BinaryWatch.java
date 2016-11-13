import java.util.ArrayList;
import java.util.List;

public class Solution {

    private int numberOfOnes(int num) {
        int cnt = 0;
        while (num != 0) {
            ++cnt;
            num = num & (num - 1);
        }
        return cnt;
    }

    public List<String> readBinaryWatch(int num) {
        List<String> res = new ArrayList<>();
        for (int i = 0; i < 1 << 4; ++i) {
            for (int j = 0; j < 1 << 6; ++j) {
                if (numberOfOnes(i) + numberOfOnes(j) == num && j < 60 && i < 12) {
                    String val = String.valueOf(j);
                    while (val.length() < 2) val = "0" + val;
                    val = i + ":" + val;
                    res.add(val);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.readBinaryWatch(5).forEach(s -> System.out.println(s));
    }
}