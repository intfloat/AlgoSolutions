
 class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
 }

public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (null == root) {
            return "N";
        } else {
            String left = serialize(root.left);
            String right = serialize(root.right);
            return String.valueOf(root.val) + " " + left.length() + " " + left + right;
        }
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.charAt(0) == 'N') {
            return null;
        } else {
            int pos = data.indexOf(' ');
            int val = Integer.valueOf(data.substring(0, pos));
            int left_pos = data.indexOf(' ', pos + 1);
            int left_chars = Integer.valueOf(data.substring(pos + 1, left_pos));
            TreeNode root = new TreeNode(val);
            root.left = deserialize(data.substring(left_pos + 1, left_pos + 1 + left_chars));
            root.right = deserialize(data.substring(left_pos + 1 + left_chars));
            return root;
        }
    }

}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
