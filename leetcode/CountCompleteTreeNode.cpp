// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
private:
    int h, low, up;
public:
    bool check(int mid, TreeNode* root) {
        TreeNode* ptr = root;
        for (int i = 0; i < h; ++i) {
            if ((1 << (h - i - 1)) & mid) {
                ptr = ptr->right;
            }
            else {
                ptr = ptr->left;
            }
        }
        return (ptr != NULL);
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        h = 0;
        TreeNode* ptr = root;
        while (ptr->left != NULL) {
            ++h;
            ptr = ptr->left;
        }
        int res = (1 << h);
        low = 0;
        up = (1 << h) - 1;
        while (low + 1 < up) {
            int mid = (low + up) / 2;
            if (!check(mid, root)) {
                up = mid - 1;
            }
            else {
                low = mid;
            }
        }
        if (check(up, root)) res += up;
        else res += low;
        return res;
    }
};
