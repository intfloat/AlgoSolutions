#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    bool find_key(TreeNode* root, int key, TreeNode*& parent, TreeNode*& target) {
        parent = NULL;
        target = root;
        while (target != NULL && target->val != key) {
            if (target->val < key) {
                parent = target;
                target = target->right;
            } else {
                parent = target;
                target = target->left;
            }
        }
        return (target != NULL);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (NULL == root) {
            return root;
        }
        TreeNode *parent = NULL, *to_del = NULL;
        if (!find_key(root, key, parent, to_del)) {
            return root;
        }
        assert(to_del->val == key);

        if (to_del->left == NULL && to_del->right == NULL) {
            if (parent == NULL) {
                return NULL;
            } else if (parent->left == to_del) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
            return root;
        } else if (to_del->left == NULL) {
            if (parent == NULL) {
                return to_del->right;
            } else if (parent->left == to_del) {
                parent->left = to_del->right;
            } else {
                parent->right = to_del->right;
            }
            return root;
        } else if (to_del->right == NULL) {
            if (parent == NULL) {
                return to_del->left;
            } else if (parent->left == to_del) {
                parent->left = to_del->left;
            } else {
                parent->right = to_del->left;
            }
            return root;
        } else {
            TreeNode* r_node = to_del->right;
            if (r_node->left == NULL) {
                r_node->left = to_del->left;
                if (parent == NULL) {
                    return r_node;
                } else if (parent->left == to_del) {
                    parent->left = r_node;
                } else {
                    parent->right = r_node;
                }
                return root;
            } else {
                TreeNode* pl_node = r_node;
                TreeNode* l_node = r_node->left;
                while (l_node->left != NULL) {
                    pl_node = pl_node->left;
                    l_node = l_node->left;
                }
                pl_node->left = l_node->right;
                l_node->left = to_del->left;
                l_node->right = to_del->right;
                if (parent == NULL) {
                    return l_node;
                } else if (parent->left == to_del) {
                    parent->left = l_node;
                } else {
                    parent->right = l_node;
                }
                return root;
            }
        }
    }
};

int main() {
    return 0;
}
