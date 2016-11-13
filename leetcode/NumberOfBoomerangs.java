import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Solution {

    private int dis(int[] a, int[] b) {
        int dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

    public int numberOfBoomerangs(int[][] points) {
        int res = 0;
        for (int i = 0; i < points.length; ++i) {
            List<Integer> d = new ArrayList<>();
            for (int j = 0; j < points.length; ++j) {
                d.add(dis(points[i], points[j]));
            }
            Collections.sort(d);
            int l = 0, r = 0;
            while (l < d.size()) {
                while (r < d.size() && d.get(r).equals(d.get(l))) {
                    ++r;
                }
                res += (r - l) * (r - l - 1);
                l = r;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.numberOfBoomerangs(new int[][]{
                {0, 0}, {1, 0}, {2, 0}
        }));
    }
}