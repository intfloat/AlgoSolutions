/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL) return 0;
        if (root->children.empty()) return 1;
        int res = 0;
        for (int i = 0; i < root->children.size(); ++i) {
            res = max(res, maxDepth(root->children[i]));
        }
        return res + 1;
    }
};