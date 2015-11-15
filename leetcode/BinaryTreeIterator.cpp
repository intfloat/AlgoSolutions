/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #define WHITE 0
 #define GRAY 1
 #define BLACK 2
class BSTIterator {

private:
    stack<pair<TreeNode *, int> > s;
public:
    BSTIterator(TreeNode *root) {
        while (root != NULL) {
            s.push(make_pair(root, WHITE));
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) return false;
        if (s.top().second == WHITE) return true;
        if (s.top().second == GRAY) {
            while (!s.empty() && (s.top().second == BLACK
                                    || (s.top().second == GRAY && s.top().first->right == NULL ) ))
                s.pop();
            if (s.empty()) return false;
            if (s.top().second == GRAY) {
                s.top().second = BLACK;
                s.push(make_pair(s.top().first->right, WHITE));
                while (s.top().first->left != NULL) s.push(make_pair(s.top().first->left, WHITE));
            }
        }
        return true;
    }

    /** @return the next smallest number */
    int next() {
        s.top().second = GRAY;
        return s.top().first->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
