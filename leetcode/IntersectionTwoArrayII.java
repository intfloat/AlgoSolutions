import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> res = new ArrayList<Integer>();
        int p1 = 0, p2 = 0;
        while (p1 < nums1.length && p2 < nums2.length) {
            if (nums1[p1] == nums2[p2]) {
                res.add(nums1[p1]);
                ++p1;
                ++p2;
            }
            else if (nums1[p1] < nums2[p2]) {
                ++p1;
            }
            else {
                ++p2;
            }
        }
        int[] ret = new int[res.size()];
        for (int i = 0; i < res.size(); ++i) {
            ret[i] = res.get(i);
        }
        return ret;
    }
}
