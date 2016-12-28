public class Solution {
    private static final int[] dir_x = {0, 0, 1, -1};
    private static final int[] dir_y = {1, -1, 0, 0};

    public int islandPerimeter(int[][] grid) {
        int res = 0;
        for (int i = 0; i < grid.length; ++i) {
            for (int j = 0; j < grid[i].length; ++j) {
                if (grid[i][j] != 1) {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    int nx = dir_x[k] + i;
                    int ny = dir_y[k] + j;
                    if (nx < 0 || nx >= grid.length || ny < 0 || ny >= grid[i].length || grid[nx][ny] == 0) {
                        ++res;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[][] grid = new int[][]{
                {0,1,0,0},
                {1,1,1,0},
                {0,1,0,0},
                {1,1,0,0}
        };
        System.out.println(solution.islandPerimeter(grid));
    }
}