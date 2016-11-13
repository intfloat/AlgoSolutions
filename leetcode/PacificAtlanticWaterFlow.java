import java.util.*;

public class Solution {

    private int[][] matrix;
    private boolean[][] pacific, atlantic;
    private static final int[] dir_x = {1, -1, 0, 0};
    private static final int[] dir_y = {0, 0, 1, -1};

    private void bfs(int i, int j, boolean[][] arr) {
        Queue<int[]> queue = new LinkedList<>();
        arr[i][j] = true;
        queue.add(new int[]{i, j});
        while (!queue.isEmpty()) {
            int[] tp = queue.poll();
            for (int k = 0; k < 4; ++k) {
                int nr = tp[0] + dir_x[k], nc = tp[1] + dir_y[k];
                if (nr < 0 || nr >= matrix.length || nc < 0 || nc >= matrix[0].length
                        || matrix[nr][nc] < matrix[tp[0]][tp[1]] || arr[nr][nc]) {
                    continue;
                }
                arr[nr][nc] = true;
                queue.add(new int[]{nr, nc});
            }
        }
    }

    public List<int[]> pacificAtlantic(int[][] matrix) {
        List<int[]> res = new ArrayList<>();
        if (matrix.length == 0) {
            return res;
        }
        this.matrix = matrix;
        int row = matrix.length, col = matrix[0].length;
        this.pacific = new boolean[row][col];
        this.atlantic = new boolean[row][col];
        for (int i = 0; i < row; ++i) {
            Arrays.fill(pacific[i], false);
            Arrays.fill(atlantic[i], false);
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 || j == 0) {
                    bfs(i, j, pacific);
                }
                if (i + 1 == row || j + 1 == col) {
                    bfs(i, j, atlantic);
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.add(new int[]{i, j});
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] matrix = new int[][]{
                {1,2,2,3,5},
                {3,2,3,4,4},
                {2,4,5,3,1},
                {6,7,1,4,5},
                {5,1,1,2,4}
        };
        for (int[] e : solution.pacificAtlantic(matrix)) {
            System.out.println("[" + e[0] + ", " + e[1] + "]");
        }
    }
}