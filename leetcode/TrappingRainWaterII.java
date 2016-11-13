import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {

    private static int[] dir_x = {0, 1, 0, -1};
    private static int[] dir_y = {1, 0, -1, 0};

    public int trapRainWater(int[][] heightMap) {
        if (null == heightMap || heightMap.length <= 1) {
            return 0;
        }
        int row = heightMap.length, col = heightMap[0].length;
        boolean[][] visited = new boolean[row][col];
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                visited[i][j] = false;
            }
        }
        PriorityQueue<Node> pq = new PriorityQueue<Node>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o1.val - o2.val;
            }
        });
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (i == 0 || j == 0 || i + 1 == row || j + 1 == col) {
                    visited[i][j] = true;
                    pq.add(new Node(i, j, heightMap[i][j]));
                }
            }
        }
        int res = 0;
        while (!pq.isEmpty()) {
            Node tp = pq.poll();
            for (int i = 0; i < 4; ++i) {
                int nr = tp.i + dir_x[i], nc = tp.j + dir_y[i];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col || visited[nr][nc]) {
                    continue;
                }
                visited[nr][nc] = true;
                if (heightMap[nr][nc] < heightMap[tp.i][tp.j]) {
                    res += heightMap[tp.i][tp.j] - heightMap[nr][nc];
                }
                heightMap[nr][nc] = Math.max(heightMap[nr][nc], heightMap[tp.i][tp.j]);
                pq.add(new Node(nr, nc, heightMap[nr][nc]));
            }
        }
        return res;
    }

    static class Node {
        private int i, j, val;
        public Node(int i, int j, int v) {
            this.i = i;
            this.j = j;
            this.val = v;
        }
    }

    public static void main(String[] args) {
        int[][] height = new int[][]{
                {1,4,3,1,3,2},
                {3,2,1,3,2,4},
                {2,3,3,2,3,1}
        };
        Solution solution = new Solution();
        System.out.println(solution.trapRainWater(height));
    }
}