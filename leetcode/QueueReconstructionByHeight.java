import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;

public class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] != o2[0]) {
                    return o2[0] - o1[0];
                } else {
                    return o1[1] - o2[1];
                }
            }
        });
        ArrayList<int[]> arr = new ArrayList<>();
        for (int i = 0; i < people.length; ++i) {
            arr.add(people[i][1], people[i]);
        }
        int[][] res = new int[people.length][2];
        for (int i = 0; i < people.length; ++i) {
            res[i] = arr.get(i);
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] res = solution.reconstructQueue(new int[][]{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}});
        for (int[] e : res) {
            System.out.println("[" + e[0] + ", " + e[1] + "]");
        }
    }
}