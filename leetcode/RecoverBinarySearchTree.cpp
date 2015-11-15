/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

TreeNode* findNodes(TreeNode* root, TreeNode* prev, TreeNode* nodes[2]) {
    if (!root) {
        return prev;
    }
    TreeNode* previous = findNodes(root->left, prev, nodes);

    if (previous && previous->val > root->val) {
        if (!nodes[0] && !nodes[1]) {
            nodes[0] = previous;
            nodes[1] = root;
        } else {
            nodes[1] = root;
        }
    }
    return findNodes(root->right, root, nodes);
}

void recoverTree(TreeNode *root) {
    TreeNode* nodes[2] = {NULL, NULL};
    findNodes(root, NULL, nodes);
    int temp = nodes[0]->val;
    nodes[0]->val = nodes[1]->val;
    nodes[1]->val = temp;
 }
};
