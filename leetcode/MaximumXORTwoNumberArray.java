public class Solution {

    static class Node {
        public Node left;
        public Node right;
        public Node() {
            this.left = null;
            this.right = null;
        }
    }

    private Node root;

    private void insert(Node node, int num, int pos) {
        if (pos < 0) {
            return;
        }
        if ((num & (1 << pos)) > 0) {
            if (node.right == null) {
                node.right = new Node();
            }
            insert(node.right, num, pos - 1);
        } else {
            if (node.left == null) {
                node.left = new Node();
            }
            insert(node.left, num, pos - 1);
        }
    }

    private int find(Node node, int num, int pos) {
        if (pos < 0) {
            return 0;
        }
        if ((num & (1 << pos)) > 0) {
            if (node.left == null) {
                return find(node.right, num, pos - 1);
            } else {
                return (1 << pos) + find(node.left, num, pos - 1);
            }
        } else {
            if (node.right == null) {
                return find(node.left, num, pos - 1);
            } else {
                return (1 << pos) + find(node.right, num, pos - 1);
            }
        }
    }

    public int findMaximumXOR(int[] nums) {
        this.root = new Node();
        for (int i = 0; i < nums.length; ++i) {
            this.insert(this.root, nums[i], 31);
        }
        int res = 0;
        for (int i = 0; i < nums.length; ++i) {
            res = Math.max(res, find(this.root, nums[i], 31));
        }
        return res;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.findMaximumXOR(new int[]{3, 10, 5, 25, 2, 8}));
    }
}