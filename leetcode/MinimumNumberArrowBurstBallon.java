import java.util.Arrays;
import java.util.Comparator;

public class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int res = 0, pv = 0;
        for (int i = 0; i < points.length; ++i) {
            if (i == 0 || points[i][0] > pv) {
                ++res;
                pv = points[i][1];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] points = new int[][]{
                {-2147483648,2147483647}
        };
        System.out.println(solution.findMinArrowShots(points));
    }
}