///**
// * Definition for a binary tree node.
// * * /

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if (null == root) {
            return 0;
        } else {
            int ret = 0;
            if (null != root.left && null == root.left.left && null == root.left.right) {
                ret += root.left.val;
            }
            return ret + sumOfLeftLeaves(root.left) + sumOfLeftLeaves(root.right);
        }
    }
}