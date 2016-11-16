import java.util.HashMap;

public class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int n = A.length;
        HashMap<Integer, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = A[i] + B[j];
                if (cnt.containsKey(val)) {
                    cnt.put(val, cnt.get(val) + 1);
                } else {
                    cnt.put(val, 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int val = -(C[i] + D[j]);
                if (cnt.containsKey(val)) {
                    res += cnt.get(val);
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.fourSumCount(new int[]{1, 2}, new int[]{-2, -1}, new int[]{-1, 2}, new int[]{0, 2}));
    }
}