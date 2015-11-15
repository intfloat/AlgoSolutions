// PopulatingNextRightPointersInEachNodeII.cpp

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
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        root->next = NULL;
        set(root);
        return;
    }

    void set(TreeLinkNode *node){
        if(node == NULL) return;
        if(node->left==NULL && node->right==NULL) return;       
        if(node->left!=NULL && node->right!=NULL){
            node->left->next = node->right;
        }
        if(node->right!=NULL){      
            TreeLinkNode *tmp = node->next;
            while(tmp != NULL){
                if(tmp->left!=NULL){
                    node->right->next = tmp->left;
                    break;
                }
                else if(tmp->right!=NULL){
                    node->right->next = tmp->right;
                    break;
                }
                else{
                    tmp = tmp->next;
                }
            }
            if(tmp==NULL) node->right->next = NULL;
        }
        if(node->left!=NULL && node->right==NULL){
            TreeLinkNode *tmp = node->next;
            while(tmp != NULL){
                if(tmp->left!=NULL){
                    node->left->next = tmp->left;
                    break;
                }
                else if(tmp->right!=NULL){
                    node->left->next = tmp->right;
                    break;
                }
                else{
                    tmp = tmp->next;
                }
            }
            if(tmp==NULL) node->left->next = NULL;  
        }       
        set(node->right);
        set(node->left);
        return;
    }

};