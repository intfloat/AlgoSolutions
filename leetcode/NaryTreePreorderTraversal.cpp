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
    vector<int> preorder(Node* root) {
        stack<Node*> st;
        vector<int> res;
        if (NULL == root) {
            return res;
        }
        st.push(root);
        while (!st.empty()) {
            Node* tp = st.top();
            st.pop();
            if (NULL == tp) continue;
            res.push_back(tp->val);
            int c_sz = tp->children.size();
            for (int i = c_sz - 1; i >= 0; --i) {
                st.push(tp->children[i]);
            }
        }
        return res;
    }
};