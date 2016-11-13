import java.util.HashMap;

///**
// * Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    private int sum;
    private HashMap<Integer, Integer> mp;
    private int res;

    private void dfs(TreeNode node, int val) {
        if (node == null) {
            return;
        }
        int nval = val + node.val;
        if (nval == this.sum) {
            ++res;
        }
        if (this.mp.containsKey(nval - this.sum)) {
            res += this.mp.get(nval - this.sum);
        }
        if (!this.mp.containsKey(nval)) {
            this.mp.put(nval, 1);
        } else {
            this.mp.put(nval, 1 + this.mp.get(nval));
        }
        dfs(node.left, nval);
        dfs(node.right, nval);
        this.mp.put(nval, this.mp.get(nval) - 1);
    }

    public int pathSum(TreeNode root, int sum) {
        this.sum = sum;
        this.mp = new HashMap<>();
        this.res = 0;
        dfs(root, 0);
        return this.res;
    }
}