// PopulatingNextRightPointersInEachNode.cpp

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // use recursion is much more cleaner
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next = NULL;              
        set(root);
        return;
    }

    void set(TreeLinkNode *node){
        if(node == NULL) return;
        if(node->left == NULL) return;
        node->left->next = node->right;
        if(node->next == NULL){
            node->right->next = NULL;
        }
        else{
            node->right->next = node->next->left;
        }
        set(node->left);
        set(node->right);
        return;
    }
};